#include <string>
class Soundex {
  public:
  std::string encode(const std::string &in) const noexcept {
    return in;
  }
};

#include "gmock/gmock.h"

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
  Soundex soundex;
  auto encoded = soundex.encode("A");
  ASSERT_EQ(encoded, "A");
}

