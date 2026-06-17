#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>


int main()
{
    std::cout << __cplusplus << '\n';
    std::string path = "C:\\Users\\Light\\Desktop\\Politics-l-Assembl-e\\FR\\Planesculptors\\politics-files\\";
    std::fstream input(path+"set.txt");
    std::ofstream output(path+"temp.txt");

    if (!input)
    {
        std::cout<<"coucou"<<std::endl;
        exit(0);
    }
    std::string ligne;
    std::string s = " et ";

    while(std::getline(input,ligne))
    {
        if(ligne.size()>=s.size())
        {
            if(ligne.compare(ligne.size() - s.size(), s.size(), s) == 0)
            {
                std::cout<<ligne<<std::endl;
                ligne.erase(ligne.size() - s.size());
            }
        }
        output << ligne << '\n';
    }

    input.close();
    output.close();

    std::filesystem::remove(path+"set.txt");
    std::filesystem::rename(path+"temp.txt",path+"set.txt");
    return 0;
}
