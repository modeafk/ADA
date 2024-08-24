#include <iostream>
#include <cstdlib>  
#include <cstring>  

class CVector
{
private:
    int *m_pVect;   // Pointer to the buffer
    int m_nCount;   // Control how many elements are actually used
    int m_nMax;     // Control how many are allocated as maximum
    int m_nDelta;   // To control the growing

    void Init(int delta);  // Init our private variables, etc
    void Resize();         // Resize the vector when occurs an overflow

public:
    CVector(int delta = 10);  // Constructor
    ~CVector();               // Destructor
    void Insert(int elem);    // Insert a new element
    void Print() const;      // Print all elements in the vector
};

void CVector::Init(int delta)
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = (int*) std::malloc(sizeof(int) * m_nMax);
    if (!m_pVect) {
        std::cerr << "Memory allocation failed!\n";
        std::exit(EXIT_FAILURE);
    }
}

void CVector::Resize()
{
    int newSize = m_nMax + m_nDelta;
    int* newBuffer = (int*) std::realloc(m_pVect, sizeof(int) * newSize);
    if (newBuffer == nullptr) {
        std::cerr << "Memory allocation failed during resize!\n";
        std::exit(EXIT_FAILURE);
    }
    m_pVect = newBuffer;
    m_nMax = newSize;
}

CVector::CVector(int delta)
{
    Init(delta);
}

CVector::~CVector()
{
    std::free(m_pVect);
}

void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax) { // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    }
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Print() const
{
    for (int i = 0; i < m_nCount; ++i) {
        std::cout << m_pVect[i] << std::endl;
    }
}

int main()
{
    CVector vector; 

    for (int i = 0; i < 20; ++i) {
        vector.Insert(i);
    }
    std::cout << "Vector elements:\n";
    vector.Print();

    return 0;
}
