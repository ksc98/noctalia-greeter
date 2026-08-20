#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace power {

  // A [[session.actions]] row with action = "command" (the same shape Noctalia Shell's
  // session panel uses and syncs): rendered as an extra power button that runs `command`.
  struct CustomAction {
    std::string command;
    std::string label;
    std::string glyph;
  };

  bool powerOff();
  bool reboot();
  bool suspend();
  bool rebootToFirmwareSetup();
  bool runCommand(std::string_view command);
  // True when sync.toml configures suspend explicitly ([session.power].suspend or an
  // actions row with action = "suspend" / "lock_and_suspend"); the Sleep button is only
  // shown in that case.
  [[nodiscard]] bool hasSuspendCommand();
  [[nodiscard]] std::vector<CustomAction> customActions();
  [[nodiscard]] bool canRebootToFirmwareSetup();
  [[nodiscard]] bool hasSyncedAction(std::string_view action);
  [[nodiscard]] std::optional<std::string> syncedActionLabel(std::string_view action);
  [[nodiscard]] std::optional<std::string> syncedActionGlyph(std::string_view action);

} // namespace power
