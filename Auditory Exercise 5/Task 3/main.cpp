#include <iostream>
#include <cstring>

using namespace std;

class WebPage {
private:
    char url[100];
    char *content;

    void copy(const WebPage &wp) {
        strcpy(this->url, wp.url);
        this->content = new char[strlen(wp.content)+1];
        strcpy(this->content, wp.content);
    }
public:

    WebPage(const char *url="", const char *content=""){
        strcpy(this->url, url);
        this->content = new char[strlen(content)+1];
        strcpy(this->content, content);
    }

    WebPage(const WebPage &wp) {
        copy(wp);
    }

    WebPage& operator=(const WebPage &wp) {
        if(this != &wp) {
            copy(wp);
        }
        return *this;
    }

    bool isSame(WebPage p) {
        return strcmp(this->url, p.url) == 0;
    }

    friend class WebServer;

    ~WebPage(){
        delete[]this->content;
    }
};

class WebServer {
private:
    char server_name[30];
    int number_of_pages;
    WebPage *pages;

    void copy(const WebServer &ws) {
        strcpy(this->server_name, ws.server_name);
        this->number_of_pages = number_of_pages;
        this->pages = new WebPage[ws.number_of_pages];
        for (int i = 0; i < ws.number_of_pages; ++i) {
            this->pages[i] = ws.pages[i];
        }
    }

public:
    WebServer(const char *server_name="", int number_of_pages=0, const WebPage *pages=0) {
        strcpy(this->server_name, server_name);
        this->number_of_pages = number_of_pages;
        this->pages = new WebPage[number_of_pages];
        for (int i = 0; i < number_of_pages; ++i) {
            this->pages[i] = pages[i];
        }
    }

    WebServer(const WebServer &ws) {
        copy(ws);
    }

    WebServer& operator=(const WebServer &ws) {
        if(this!=&ws) {
            copy(ws);
        }
        return *this;
    }

    WebServer& addPage(WebPage p) {
        WebPage *tmp = new WebPage[this->number_of_pages+1];

        for (int i = 0; i < this->number_of_pages; ++i) {
            tmp[i] = this->pages[i];
        }

        tmp[number_of_pages++] = p;
        delete [] this->pages;
        this->pages = tmp;

        return *this;
    }

    WebServer& deletePage(WebPage p) {
        int newSize=0;
        for (int i = 0; i < this->number_of_pages; ++i) {
            if(!this->pages[i].isSame(p)) {
                newSize++;
            }
        }

        WebPage *tmp = new WebPage[newSize];

        newSize=0;

        for (int i = 0; i < this->number_of_pages; ++i) {
            if(!this->pages[i].isSame(p)) {
                tmp[newSize++] = this->pages[i];
            }
        }

        delete [] this->pages;
        this->pages = tmp;
        this->number_of_pages = newSize;

        return *this;
    }

    void listPages () {
        cout << "Number: " << this->number_of_pages << endl;
        for (int i = 0; i < this->number_of_pages; i++)
            cout << this->pages[i].content << "- " << this->pages[i].url << endl ;
    }

    ~WebServer(){
        delete[]this->pages;
    }
};

int main() {
    WebPage wp1 ("http://www.google.com", "The search engine");
    WebPage wp2 ("http://www.finki.ukim.mk", "FINKI");
    WebPage wp3 ("http://www.time.mk", "Site vesti");
    WebServer ws(" Server ");
    ws.addPage(wp1) ;
    ws.addPage(wp2);
    ws.addPage(wp3) ;
    ws.listPages ();
    cout << "\nAfter delete: \n";
    ws.deletePage(wp3);
    ws.listPages ();
    return 0;
}
