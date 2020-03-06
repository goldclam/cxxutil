#include <iostream>
#include <sstream>
#include <cstdio>
#include <curl/curl.h>

 
struct data {
  char trace_ascii; /* 1 or 0 */ 
};
 
 
static
int my_trace(CURL *handle, curl_infotype type,
             char *data, size_t size,
             void *userp)
{
  struct data *config = (struct data *)userp;
  const char *text;
  (void)handle; /* prevent compiler warning */ 
 
  switch(type) {
  case CURLINFO_TEXT:
    // fprintf(stderr, "== Info: %s", data);
    /* FALLTHROUGH */ 
  default: /* in case a new one is introduced to shock us */ 
    return 0;
 
  case CURLINFO_HEADER_OUT:
    text = "=> Send header";
    std::clog << "=> Send header" << std::endl;
    std::clog << std::string{data} << std::endl;
    break;

  case CURLINFO_HEADER_IN:
    ext = "<= Recv header";
    std::clog << "<= Recv header" << std::endl;
    std::clog << std::string{data} << std::endl;
    break;
  }
 
  return 0;
}
 
int curlmain(void)
{
  CURL *curl;
  CURLcode res;
  struct data config;
 
  config.trace_ascii = 1; /* enable ascii tracing */ 
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, my_trace);
    curl_easy_setopt(curl, CURLOPT_DEBUGDATA, &config);
 
    /* the DEBUGFUNCTION has no effect until we enable VERBOSE */ 
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
 
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
    curl_easy_setopt(curl, CURLOPT_URL, "https://github.com/haeram27");
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
  return 0;
}