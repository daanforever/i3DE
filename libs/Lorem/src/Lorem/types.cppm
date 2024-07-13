export module daan.i3de.lorem.types;

export import std;
export import daan.i3de.lorem.error;
export import daan.i3de.lorem.logger;

export namespace lorem {

  // Structure representing a file in memory
  struct t_file {
    t_file() = default;
    explicit t_file(std::string_view new_name) : name(new_name) {};

    virtual ~t_file() = default;

    std::string name = {};
    bool isDirectory = false;
    std::vector<std::byte> content = {};

    t_file* parent = {};
    std::vector<std::shared_ptr<t_file>> files = {};
    std::map<std::string, std::shared_ptr<t_file>, std::less<>> index = {};

    explicit operator bool() const {
      return present();
    }

    bool empty() const {
      return content.empty() && files.empty();
    }

    bool present() const {
      return !empty();
    }

    t_file& add(std::shared_ptr<t_file> new_child) {
      new_child->parent = this;
      files.emplace_back(new_child);
      index.try_emplace(new_child->name, new_child);

      return *this;
    }

    std::string string() const {
      return std::string((const char*)content.data(), content.size());
    }

    std::shared_ptr<t_file> find(const std::string& filename) const {
      auto result = std::make_shared<t_file>();

      bool search = true;
      auto ptr = this;

      while (search) {

        if (auto iter = ptr->index.find(filename); iter != ptr->index.end()) {
          result = iter->second;
          search = false;
        }
        else {
          if (ptr->name == "/") {
            search = false;
          }
          else {
            ptr = parent;
          }
        }

      }

      return result;
    }
  };

  using t_file_ptr = std::shared_ptr<t_file>;
  using t_map_ss = std::map<std::string, std::string, std::less<>>;

  enum Endianness { Little, Big };
}