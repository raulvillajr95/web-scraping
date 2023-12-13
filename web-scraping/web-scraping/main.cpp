#include <iostream>
#include <string>
#include <curl/curl.h>
#include <gumbo.h>

using namespace std;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output)
{
   size_t totalSize = size * nmemb;
   output->append(static_cast<char*>(contents), totalSize);
   return totalSize;
}

int main()
{
   CURL* curl = curl_easy_init();
   if (!curl)
   {
      cerr << "Error initializing libcurl" << endl;
      return 1;
   }
   
   curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");
   
   string htmlContent;
   
   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
   curl_easy_setopt(curl, CURLOPT_WRITEDATA, &htmlContent);
   
   // ...
   
   CURLcode res = curl_easy_perform(curl);
   
   if (res != CURLE_OK)
   {
      cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
      return 1;
   }
   
   return 0;
}
