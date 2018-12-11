#include <stdio.h>
#include <curl/curl.h>

int			main(int ac, char **av)
{
	CURL	 	*curl;
	CURLcode	res;

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, av[1]);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failde: %s\n", curl_easy_strerror(res));
		curl_easy_cleanup(curl);
		printf("%s", av[1]);
	}
	return (0);
}
