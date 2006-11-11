#ifndef NOOS_RSS__H
#define NOOS_RSS__H

#include <string>
#include <vector>

extern "C" {
#include <mrss.h>
}

namespace noos {

	class rss_item {
		public:
			rss_item() { }
			~rss_item() { }
			inline std::string& title() { return title_; }
			inline std::string& link() { return link_; }
			inline std::string& author() { return author_; }
			inline std::string& description() { return description_; }
			inline std::string& pubDate() { return pubDate_; }
		private:
			std::string title_;
			std::string link_;
			std::string author_;
			std::string description_;
			std::string pubDate_;
	};

	class rss_feed {
		public:
			rss_feed() { }
			~rss_feed() { }
			inline std::string& title() { return title_; }
			inline std::string& description() { return description_; }
			inline std::string& link() { return link_; }
			inline std::string& pubDate() { return pubDate_; }
			inline std::vector<rss_item>& items() { return items_; }

		private:
			std::string title_;
			std::string description_;
			std::string link_;
			std::string pubDate_;
			std::vector<rss_item> items_;
	};

	class rss_parser {
		public:
			rss_parser(const char * uri);
			~rss_parser();
			void parse();
			inline rss_feed& get_feed() { return feed; }
		private:
			std::string my_uri;
			mrss_t * mrss;
			rss_feed feed;
	};

}


#endif