export module daan.i3de.lorem.logger;

import std;

export namespace lorem {
  class logger {
  private:
    logger() = default;

  public:
    static logger get_instance() {
      static logger instance;
      return instance;
    }

    static logger debug() {
      return get_instance().prefix("DEBUG");
    }

    static logger info() {
      return get_instance().prefix("INFO");
    }

    static logger warning() {
      return get_instance().prefix("WARNING");
    }

    static logger error() {
      return get_instance().prefix("ERROR");
    }


    //template<class T>
    //lorem::logger operator<<(T& text) const {
    //  std::cout << text;
    //  return *this;
    //};

    template<class T>
    lorem::logger operator<<(T text) const {
      std::cout << text;
      return *this;
    };


    //lorem::logger operator<<(int num) const {
    //  std::cout << num;
    //  return *this;
    //};

    lorem::logger operator<<(std::string text) const {
      std::cout << text;
      return *this;
    };

    lorem::logger operator<<(std::stringstream const& ss) const {
      std::cout << ss.str();
      return *this;
    };

    lorem::logger operator<<(std::ostream& (*OStreamMani)(std::ostream&)) {
      std::cout << OStreamMani;
      return *this;
    };

    //lorem::logger operator<<(std::list<std::string>& strings) const {
    //  if (strings.size() > 0) {
    //    std::cout << std::endl;
    //  }

    //  for (const auto& text : strings) {
    //    std::cout << text << std::endl;
    //  }
    //  return *this;
    //};

    template<typename T>
    lorem::logger operator<<(std::vector<T> data) const {
      if (data.size() > 0) {
        std::cout << std::endl;
      }

      for (const auto& item : data) {
        std::cout << item << std::endl;
      }
      return *this;
    };

    lorem::logger operator<<(std::shared_ptr<std::string> text_ptr) const {
      std::cout << *text_ptr.get();
      return *this;
    };

    lorem::logger prefix(const std::string& level) const {
      std::cout << "[" << level << "] ";
      return *this;
    }
  };
}