#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

void 
usage ()
{
	fprintf(stderr, "Usage: fetch-rfc [Number] \n");	
}

int
getrfc (char *rfc) 
{
	
	/* the beginning of the URL for each RFC in plain text format */
	char baseurl[] = "https://www.ietf.org/rfc/rfc"; 
	
	/* .txt is the file extension for each RFC in plain text format */
	char ext[] = ".txt";
	
	/* It has to "fit" all the strings. I hope you can understand how it's done. */
	char *url = (char*)malloc(sizeof(char) * (strlen(baseurl) + strlen(rfc) + strlen(ext)));
	
	/* Create the complete URL out of the three strings */
	strcat(url, baseurl); 						
	strcat(url, rfc); 							/* append the number of the RFC */ 
	strcat(url, ext);							
	
	/* Start a libcurl easy session */
	curl_global_init(CURL_GLOBAL_DEFAULT);
	CURL *curl = curl_easy_init();
	
	if (curl) {

  		CURLcode res;
  		curl_easy_setopt(curl, CURLOPT_URL, url);

		/* Fail on HTTP 4xx errors instead of fetching the 404 page */
		curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

		/* Perform a libcurl easy session for the given url */
		res = curl_easy_perform(curl);


		/* Free the url buffer */
		free(url);

		/* Check for errors and return 0 in case there was an error */
		if (res != CURLE_OK) {
			return 0;
		} 

		/* always cleanup :) */
  		curl_easy_cleanup(curl);
	}
	
	return 1;
}

int
main (int argc, char *argv[])
{
	
/* 
 * Output a message explaining usage of fetch-rfc to stderr in case the user doesn't pass the number of the RFC as an argument.
 */
	if (argc < 2) { 
		usage(); 
		return -1;
	}
/*
 * Otherwise continue with the execution and finally fetch the RFC.
 */
	if (!getrfc(argv[1])) {
		fprintf(stderr, "%s: error: There was an error fetching the RFC. Please make sure you have entered a number of an existing RFC.\n", argv[0]);
		return -1;
	}


	return 0;
}
