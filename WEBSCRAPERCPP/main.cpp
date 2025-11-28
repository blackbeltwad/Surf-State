#include <iostream>
#include <curl/curl.h>
#include <gumbo.h>
using namespace std;



size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    static_cast<string*>(userdata)->append(ptr, size * nmemb);
    size_t realsize = size * nmemb;
    return realsize;
}

int main()
{
    CURL *curl = curl_easy_init();

    
        string memory;
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.scrapethissite.com/pages/simple/");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &memory);
        CURLcode valid = curl_easy_perform(curl);


        if (valid != CURLE_OK)
        {
            cerr << "curl_easy_perform() failed: ";
        }
        curl_easy_cleanup(curl);
        GumboOutput* output = gumbo_parse(memory.c_str());



        cout << output << endl;

    return 0;


}


