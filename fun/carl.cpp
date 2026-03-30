// liste von usern:
// name, id, aktiv

// liste von sessions:
// wie lange auf der seite, wie viele clicks

#include <string>
#include <vector>

using UUID = std::string;

struct User {
  UUID id;
  std::string name;
  bool isActive;
};

struct Session {
  UUID userId;

  // Duration in seconds
  int duration;
  int amountClicks;
};

auto findMostActiveUser(const std::vector<User> users,
                        const std::vector<Session> sessions) -> User {
  int maxDuration{0};
  std::string userId{};
  for (const auto &session : sessions) {
    if (session.duration > maxDuration) {
      maxDuration = session.duration;
      userId = session.userId;
    }
  }

  return *std::find_if(users.begin(), users.end(),
                       [](auto user) { user.id == userId });
};
