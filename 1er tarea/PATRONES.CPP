#include <vector>
#include <list>
#include <iostream>

using namespace std;

// Template function to write container contents to an output stream
template <typename Container>
void Write(Container &ds, ostream &os)
{
    typename Container::iterator iter = ds.begin(); // Use typename for dependent types
    for (; iter != ds.end(); ++iter)
        os << *iter << "\n";
}

// Class definition for a complex data structure
class CMyComplexDataStructure
{
    vector<float> m_container;

public:
    void Insert(float fVal) { m_container.push_back(fVal); }

    template <typename Functor>
    void sumone(Functor functor)

    {
        typename vector<float>::iterator iter = m_container.begin();
        for (; iter != m_container.end(); ++iter)
            functor(*iter);
    }
    void Print(ostream &os) const
        {
            for (float value : m_container)
                os << value << "\n";
        }
};

template <typename T>
class funcobjclass
{
public:
    void operator()(T &objinstance)
    {
        objinstance++;
    }
};

int main(int argc, char *argv[])
{
    list<float> mylist;
    vector<float> myvector;
    for (int i = 0; i < 10; i++)
    {
        mylist.push_back(static_cast<float>(i));
        myvector.push_back(static_cast<float>(i + 10));
    }
    Write(mylist, cout);
    Write(myvector, cout);


    CMyComplexDataStructure ds;
    ds.Insert(3.5f);
    ds.Insert(4.5f);
    ds.Insert(6.5f);
    ds.Insert(3.9f);

    funcobjclass<float> x;
    ds.sumone(x);

    // Print the modified values
    cout << "Modified values in CMyComplexDataStructure:\n";
    ds.Print(cout);

    return 0;
}

