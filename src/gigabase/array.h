//-< ARRAY.H >-------------------------------------------------------*--------*
// GigaBASE                  Version 1.0         (c) 1999  GARRET    *     ?  *
// (Post Relational Database Management System)                      *   /\|  *
//                                                                   *  /  \  *
//                          Created:     20-Nov-98    K.A. Knizhnik  * / [] \ *
//                          Last update: 20-Dec-98    K.A. Knizhnik  * GARRET *
//-------------------------------------------------------------------*--------*
// Array type for table record fields
//-------------------------------------------------------------------*--------*

#ifndef __ARRAY_H__
#define __ARRAY_H__

BEGIN_GIGABASE_NAMESPACE

/**
 * Base class for all arrays
 */
class GIGABASE_DLL_ENTRY dbAnyArray {
    friend class dbTableDescriptor;
  protected:
    size_t len;

  public:
    static void arrayAllocator(dbAnyArray* aArray, void* data, size_t length)
    {
        aArray->len = length;
        *(void**)(aArray+1) = data;
    }
    /**
     * Get number of elements
     * @return array length
     */
    size_t length() const { return len; }

    /**
     * Get pointer to array elements. You should not update them directly.
     * @return pointer to array element
     */
    void const* base() const { return *(void**)(this+1); }
};

/**
 * Template for arrays
 */
template<class T>
class dbArray : public dbAnyArray {
    friend class dbTableDescriptor;
  protected:
    T*     data;
    size_t allocated;

    static void arrayAllocator(dbAnyArray* aArray, void* data, size_t length)
    {
        dbArray<T>* array = (dbArray<T>*)aArray;
        array->len = length;
        if (array->allocated) {
            delete[] array->data;
        }
        if (data != NULL || length == 0) {
            array->data = (T*)data;
            array->allocated = 0;
        } else {
            array->data = new T[length];
            array->allocated = length;
        }
    }

    
    inline void memcpy(T* dst, T const* src, size_t len) { 
        int n = (int)len;
        while (--n >= 0) { 
            *dst++ = *src++;
        }
    }

    inline void memmove(T* dst, T const* src, size_t len) { 
        int n = (int)len;
        if (dst < src) {
            while (--n >= 0) { 
                *dst++ = *src++;
            }
        } else { 
            dst += n;
            src += n;       
            while (--n >= 0) { 
                *--dst = *--src;
            }
        }
    }

  public:
    dbFieldDescriptor* dbDescribeComponents(dbFieldDescriptor* fd) {
        fd->type = fd->appType = dbField::tpArray;
        fd->dbsSize = sizeof(dbVarying);
        fd->alignment = 4;
        fd->arrayAllocator = arrayAllocator;
        return dbDescribeField(new dbFieldDescriptor(STRLITERAL("[]"), 0, sizeof(T), 0),
                               *(T*)fd);
    }

    /**
     * Default constructor 
     */
    dbArray() {
        data = NULL;
        len = 0;
        allocated = 0;
    }

    /**
     * Construct array with specified length
     * @param size array length
     */
    dbArray(size_t size) {
        if (size != 0) {
            data = new T[size];
        }
        len = size;
        allocated = size;
    }

    /**
     * Construct array with specified content
     * @param ptr pointer to the elements
     * @param size size of array
     * @param allocate if 0, then array will just points to specified location of
     * elements, otherwise elements will be copied to the created buffer
     */
    dbArray(T const* ptr, size_t size, size_t allocate = 0) {
        len = size;
        allocated = allocate;
        if (allocate != 0) {
            assert(allocate >= size);
            data = new T[allocate];
            memcpy(data, ptr, size);
        } else {
            data = (T*)ptr;
        }
    }

    /**
     * Copy constructor
     * @param arr source array
     */
    dbArray(dbArray<T> const& arr) { // copy constructor
        allocated = arr.allocated;
        len = arr.len;
        if (allocated) {
            data = new T[allocated];
            memcpy(data, arr.data, len);
        } else {
            data = arr.data;
        }
    }

    /**
     * Destructor
     */
    ~dbArray() {
        if (allocated) {
            delete[] data;
            data = NULL;
        }
    }

    /**
     * Assignment operator
     * @return this
     */
    dbArray<T>& operator = (dbArray<T> const& arr) {
        if (this == &arr) { 
            return *this;
        }
        if (allocated) {
            delete[] data;
        }
        if ((len = arr.len) != 0) {
            data = new T[len];
            memcpy(data, arr.data, len);
        }
        allocated = len;
        return *this;
    }

    /**
     * Get last element of the array
     * @return last element of the array
     */
    T const& last() {
        assert(len > 0);
        return data[len-1];
    }

    /**
     * Assign content to the array
     * @param ptr pointer to the assigned elements
     * @param size number of elements
     * @param copy if 0, then array will just points to specified location of
     * elements, otherwise elements will be copied to the created buffer
     */
    void assign(T const* ptr, size_t size, bool copy = true) {
        if (allocated) {
            delete[] data;
        }
        len = size;
        if (copy && size != 0) {
            data = new T[size];
            memcpy(data, ptr, size);
            allocated = size;
        } else {
            data = (T*)ptr;
            allocated = 0;
        }
    }

    /**
     * Get array element with specified index.
     * @param index element index
     * @return element with specified index
     */
    T const& operator [](size_t index) const {
        assert(index < len);
        return data[index];
    }

    /**
     * Store element at the specified position
     * @param index element index
     * @param value stored element value
     */
    void putat(size_t index, T const& value) {
        assert(index < len);
        if (!allocated) {
            T* copy = new T[len];
            memcpy(copy, data, len);
            data = copy;
            allocated = len;
        }
        data[index] = value;
    }

    /**
     * Get array element with specified index.
     * @param index element index
     * @return element with specified index
     */
    T const& getat(size_t index) const {
        assert(index < len);
        return data[index];
    }

    /**
     * Make array empty
     */
    void clear() {
        if (allocated) {
            delete[] data;
        }
        data = NULL;
        len = 0;
        allocated = 0;
    }

    /**
     * Resize array
     * @param size new array size
     */
    void resize(size_t size) {
        if (size > len && size > allocated) {
            T* p = new T[size];
            memcpy(p, data, len);
            if (allocated) {
                delete[] data;
            }
            data = p;
            allocated = size;
        }
        len = size;
    }

    /**
     * Append value to the array
     * @param value appended element
     */
    void append(T const& value) {
        insert(value, len);
    }

    /**
     * Insert element in the array at specified position
     * @param value inserted value
     * @param index insert position
     */
    void insert(T const& value, size_t index = 0) {
        assert(index <= len);
        if (len >= allocated) {
            size_t newSize = len == 0 ? 8 : len*2;
            T* p = new T[newSize];
            memcpy(p, data, index);
            p[index] = value;
            memcpy(p+index+1, data+index, (len-index));
            if (allocated) {
                delete[] data;
            }
            data = p;
            allocated = newSize;
        } else {
            memmove(data+index+1, data+index, (len-index));
            data[index] = value;
        }
        len += 1;
    }

    /** 
     * Remove element a specified position.
     * @param index position of the deleted element
     */
    void remove(size_t index) {
        assert(index < len);
        len -= 1;
        if (index != len && !allocated) {
            T* p = new T[len];
            memcpy(p, data, index);
            memcpy(p+index, data+index+1, (len-index));
            allocated = len;
            data = p;
        } else {
            memmove(data+index, data+index+1, (len-index));
        }
    }

    /**
     * Get pointer to array elements. You should not directly change them.
     * @return array elements
     */
    T const* get() const { return data; }

    /**
     * Get pointer to array elements to perform update.
     * @return array elements
     */
    T* update() { 
        if (!allocated) {
            T* copy = new T[len];
            memcpy(copy, data, len);
            data = copy;
            allocated = len;
        }
        return data; 
    }
};

/**
 * Search for first accurance of specified value in the array
 * @param value searched value
 * @return index of first element with such value or -1 if there are not such element
 */
template<class T>
int index(dbArray<T> const& a, T value) {
    for (int i = 0, n = a.length(); i < n; i++) {
      if (a[i] == value) {
          return i;
      }
    }
    return -1;
}

/**
 * Search for last accurance of specified value in the array
 * @param value searched value
 * @return index of last element with such value or -1 if there are not such element
 */
template<class T>
int rindex(dbArray<T> const& a, T value) {
    int i = a.length();
    while (--i >= 0 && a[i] != value);
    return i;
}

END_GIGABASE_NAMESPACE

#endif

