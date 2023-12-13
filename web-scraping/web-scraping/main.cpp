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

void parseAndPrintHTML(const string& htmlContent)
{
   GumboOutput* output = gumbo_parse(htmlContent.c_str());
   
   GumboNode* root = output->root;
   for (unsigned int i = 0; i < root->v.element.children.length; ++i)
   {
      GumboNode* child = static_cast<GumboNode*>(root->v.element.children.data[i]);
      if (child->type == GUMBO_NODE_ELEMENT)
      {
         cout << "Tag: " << gumbo_normalized_tagname(child->v.element.tag) << endl;
      }
   }
   
   gumbo_destroy_output(&kGumboDefaultOptions, output);
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
   
   CURLcode res = curl_easy_perform(curl);
   if (res != CURLE_OK)
   {
      cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
      return 1;
   }
   
   parseAndPrintHTML(htmlContent);
   
   curl_easy_cleanup(curl);
   
   return 0;
}
