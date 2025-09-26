#include <iostream>
#include <curl/curl.h>
using namespace std;

class  Memory {
public:
    char *data;
    size_t size;
};

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {

    size_t realsize = size * nmemb;
    auto *newm = static_cast<Memory *>(userdata);
    char *temp = new char[newm->size + realsize + 1];
    memcpy(temp, newm->data, newm->size);
    memcpy(temp + newm->size, ptr, realsize);

    delete[] newm->data;
    newm->data = temp;
    newm->size += realsize;
    newm->data[newm->size] = '\0';


    return realsize;
}

int main()
{
    CURL *curl;
    curl = curl_easy_init();
    bool valid;

    if (curl)
    {
        Memory memory {};
        memory.data = static_cast<char*> (malloc(1));
        memory.size = 1;

        curl_easy_setopt(curl, CURLOPT_URL, "https://www.scrapethissite.com/pages/simple/");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "JENNIFER-LAWRENCE");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &memory);

        valid = curl_easy_perform(curl);
        if (valid != CURLE_OK)
        {
            cerr << "curl_easy_perform() failed: ";
        }
        curl_easy_cleanup(curl);
        cout << memory.data << endl;
        delete [] memory.data;
        return 1;
    }


}


