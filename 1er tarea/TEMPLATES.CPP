#include <iostream>
#include <cstdlib>
#include <cstring> 

template <typename Type>
class CVector
{
private:
    Type* m_pVect; // Pointer to the buffer
    int m_nCount;  // Control how many elements are actually used
    int m_nMax;    // Control the number of allocated elements
    int m_nDelta;  // To control the growing

    void Init(int delta); // Init our private variables, etc
    void Resize();        // Resize the vector when overflow occurs

public:
    CVector(int delta = 10); // Constructor
    ~CVector();             // Destructor
    void Insert(Type elem); // Insert a new element
    void Print() const;    // Print all elements
};


template <typename Type>
void CVector<Type>::Init(int delta)
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = (Type*) std::malloc(sizeof(Type) * m_nMax);
    if (!m_pVect) {
        std::cerr << "Memory allocation failed!\n";
        std::exit(EXIT_FAILURE);
    }
}

template <typename Type>
void CVector<Type>::Resize()
{
    int newSize = m_nMax + m_nDelta;
    Type* newBuffer = (Type*) std::realloc(m_pVect, sizeof(Type) * newSize);
    if (newBuffer == nullptr) {
        std::cerr << "Memory allocation failed during resize!\n";
        std::exit(EXIT_FAILURE);
    }
    m_pVect = newBuffer;
    m_nMax = newSize;
}

template <typename Type>
CVector<Type>::CVector(int delta)
{
    Init(delta);
}
template <typename Type>
CVector<Type>::~CVector()
{
    std::free(m_pVect);
}

// Define the Insert method
template <typename Type>
void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax) { // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    }
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

// Define the Print method
template <typename Type>
void CVector<Type>::Print() const
{
    for (int i = 0; i < m_nCount; ++i) {
        std::cout << m_pVect[i] << std::endl;
    }
}

int main()
{
    CVector<int> v; 

    for (int i = 0; i < 10; ++i) {
        v.Insert(i);
    }
  
    std::cout << "Vector elements:\n";
    v.Print();

    return 0;
}
