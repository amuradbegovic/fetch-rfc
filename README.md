# fetch-rfc

A small tool for fetching [RFCs](https://en.wikipedia.org/wiki/Request_for_Comments) written using [libcurl](https://curl.se/libcurl/). 
The source of the RFCs is <https://www.ietf.org/rfc/>.

## Installation
Before attempting to build or install fetch-rfc, make sure you have all the dependencies available on your system. These include:

- libcurl4
- A C99 compiler
- make 

To build fetch-rfc, simply run `make`.
To install, run `make install` as root. 

## Usage 

```Usage: fetch-rfc [Number]```

Works the best with [less(1)](https://man7.org/linux/man-pages/man1/less.1.html).

```fetch-rfc 1149 | less```

## Issues
Despite being such a simple piece of software, fetch-rfc is still rough around the edges as I haven't tested all the edge cases and the error handling isn't very detailed. It also hasn't been tested on Windows but it should work. If you notice any bugs, open an issue. 

## License
I released fetch-rfc into public domain. See the `LICENSE` file for more details.
