![Logo](https://cdn.prod.website-files.com/66e19e0f647d489737328085/68ffedd953d37b71170e2599_QPACK.png)


# Captive Portal QuackPack for ClusterDuck Protocol

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](LICENSE)
[![ClusterDuck Protocol](https://img.shields.io/badge/ClusterDuck-Protocol-yellow.svg)](https://github.com/ClusterDuck-Protocol/ClusterDuck-Protocol)

A basic captive portal for use with the [ClusterDuck Protocol](https://github.com/ClusterDuck-Protocol/ClusterDuck-Protocol). The Captvie portal includes some device configuration settings, as well as a message interface to send emergency text-based messages across the mesh. 

## Hardware Requirements

### Supported Boards
- **Primary**: [e.g., TTGO T-Beam v1.1 with SX1262]
- **Also Tested**: [e.g., Heltec LoRa 32 V3]

## Deployment Options

### Option 1: Manual Integration (PlatformIO)
Follow the instructions detailed on the [Install section of the CDP Wiki.](https://github.com/ClusterDuck-Protocol/ClusterDuck-Protocol/wiki/platformio)

### Option 2: Deploy via OWL DMS
This QuackPack is available in the [OWL DMS](https://www.owlintegrations.com/) (Device Management System). 

1. Visit the [OWL DMS](https://www.owlintegrations.com/)
2. Select this QuackPack from the community library
3. Configure your device settings
4. Flash directly to your Duck device

## Basic Usage

**To submit your QuackPack to the DMS:** Email **support@owlintegrations.com** with your repository details.


## Message Format

[Document the message format your QuackPack uses for communication]

### Outgoing Messages
```json
{
  "device": "DUCK001",
  "type": "[message_type]",
  "data": {
    "[field1]": "[value1]",
    "[field2]": "[value2]"
  },
  "timestamp": 1234567890
}
```

### Incoming Messages
[Document what messages your QuackPack can receive and handle]


## Compatibility

- **ClusterDuck Protocol Version**: network-routing branch (v5.0+)
- **PlatformIO**: 6.0+
- **ESP32 Core**: 2.0.0+
- **Development Environment**: PlatformIO only (Arduino IDE not supported)

## Resources

- [OWL Integrations](https://www.owlintegrations.com/)
- [OWL DMS](https://www.owlintegrations.com/) - Device Management System for mesh networking
- [ClusterDuck Protocol](https://github.com/ClusterDuck-Protocol/ClusterDuck-Protocol)
- [Discord Community](https://discord.gg/clusterduck)
- **DMS Support**: support@owlintegrations.com

## Contributing

Contributions are welcome! Please follow the [ClusterDuck Protocol Contributing Guidelines](https://github.com/ClusterDuck-Protocol/ClusterDuck-Protocol/blob/master/CONTRIBUTING.md).

## License

This project is licensed under the Apache 2.0 License - see the [LICENSE](LICENSE) file for details.

Built on the [ClusterDuck Protocol](https://github.com/ClusterDuck-Protocol/ClusterDuck-Protocol) by [OWL Integrations](https://www.owlintegrations.com/).

