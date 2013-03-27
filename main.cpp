// main.cpp -- downloads a file and displays contents
// File Version: 1.2

// standard libraries
#include <iostream>

// versidyne libraries
#include "http.h"
#include "text.h"

// namespaces
using namespace std;

// main program code
int main (int argc, char *argv[]) {
	
	//declare variables
	http web;
	text file;
	
	// display usage & exit
	if (argc == 1) { cout << "usage: " << argv[0] << " file" << "\n"; return 0; }
	
	// set filename
	file = argv[1];
	
	// Initialize Memory
	file.set("links", "www.versidyne.com", web.links(web.body(web.get("www.versidyne.com", "/"))));
	
	// Retreive Sitemap
	//cout << web.get("www.versidyne.com", "/sitemap.xml") << "\n";
	
	// api test
	cout << web.get("api.versidyne.com", "/?info=ip") << "\n";
	cout << web.get("api.versidyne.com", "/?info=servername") << "\n";
	cout << web.get("api.versidyne.com", "/?login=email&pass=password") << "\n";
	cout << web.get("api.versidyne.com", "/?info=channels&session=session") << "\n";
	
	// Add links to file
	file.set("links", "www.versidyne.com", web.links(web.body(web.get("www.versidyne.com", "/"))));
	//cout << web.body(web.get("www.versidyne.com", "/")) << "\n";
	//cout << web.links(web.body(web.get("www.versidyne.com", "/"))) << "\n";
	file.set("links", "www.google.com", web.links(web.body(web.get("www.google.com", "/"))));
	//cout << web.body(web.get("www.google.com", "/")) << "\n";
	//cout << web.links(web.body(web.get("www.google.com", "/"))) << "\n";
	
	// Add data to file
	file.set("data", "www.versidyne.com", "null");
	file.set("data", "www.google.com", "null");
	
	// exit
	return 0;
	
}
