#ifndef K_HELLO_WORLD_H_
#define K_HELLO_WORLD_H_

class HelloWorld: public KryptoNinja {
  public:
    HelloWorld()
    {
      option.arguments = { {
        {"subject", "NAME", "World", "say hello to NAME (default: 'World')"}
      }, [](
        unordered_map<string, string> &str,
        unordered_map<string, int>    &num,
        unordered_map<string, double> &dec
      ) {
        if (str["subject"].empty())
          error("CF", "Invalid empty --subject value");
        else str["subject"] += "!";
      } };
    };
  protected:
    void run() {
      const string result = greeting();
      const string prefix = "Executed " + (
        option.num("debug")
          ? string(__PRETTY_FUNCTION__)
          : option.str("title")
      );
      exit(prefix + ' ' + result);
    };
  private:
    const string greeting() {
      cout << "Hello, " << option.str("subject") << endl;
      return "OK";
    };
} K;

#endif
