#include <iostream>
#include <string>
/*** Declares Template Class ***/
template<typename T>
class CStringNiFix
{
public:
    size_t getNiCount(const T& testString);//counts number of times 'Ni' occurs in testString
    void replaceNiWithNI( T& testString) ; //Corrects all Ni to NI.
};

/*** getNiCount Implementation ***/
template<typename T>
size_t CStringNiFix<T>::getNiCount(const T& testString)
{
    size_t count = 0;
    for (size_t i = 0; i < testString.length(); ++i)
    {
        if (testString[i] == 'N' && testString[i + 1] == 'i' &&
            (testString[i+2] == ' '|| ispunct(testString[i + 2]) || i+2 == testString.length() )  )
        {       //finds Ni and checks its not part of a longer word.
            ++count;
            i+=2;//if we find it then we can skip next 3 letters
        }
    }
    return count;
}

/*** replaceNiWithNI Implementation ***/
template<typename T>
void CStringNiFix<T>::replaceNiWithNI( T& testString)
{
    for (size_t i = 0; i < testString.length(); ++i)
    {
        if (testString[i] == 'N' && testString[i + 1] == 'i' &&
            (testString[i+2] == ' '|| ispunct(testString[i + 2]) || i+2 == testString.length() )  )
        {
            testString[i + 1] = 'I';
            i+=2;
        }
    }
}


int main()
{
    const char* szTestString1 = "Ni nI NI nI Ni";               //first string
    std::string strTestString1(szTestString1);
    std::cout << "String 1: \" "<< strTestString1 << "\""<< '\n';

    CStringNiFix<std::string> cStringNiFix;                     //declares std::string type of the CStringNiFix class

    size_t count = cStringNiFix.getNiCount(strTestString1);     //invokes getNiCount of cStringNiFix
    cStringNiFix.replaceNiWithNI(strTestString1);               //invokes replaceNiWithNI of cStringNiFix

    std::cout << "Found " << count << " occurrences of Ni. "
              << "New string: " << strTestString1 << '\n';


    const wchar_t* szTestString2 = L"Ni nI NI nI Ni";           //second string, in Unicode
    std::wstring strTestString2(szTestString2);
    std::wcout << L"String 2: \" "<< strTestString2 << "\""<< '\n';

    CStringNiFix<std::wstring> cWStringNiFix;                    //declares std::wstring type of the CStringNiFix class

    count = cWStringNiFix.getNiCount(strTestString2);            //invokes getNiCount of cWStringNiFix
    cWStringNiFix.replaceNiWithNI(strTestString2);               //invokes replaceNiWithNI of cWStringNiFix

    std::wcout << L"Found " << count << L" occurrences of Ni. "
             << L"New string: " << strTestString2 << '\n';


  return 0;
}
