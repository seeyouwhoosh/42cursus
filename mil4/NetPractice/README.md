*This project has been created as part of the 42 curriculum by xwu.*

# NetPractice

## Description

NetPractice is a hands-on networking project from the 42 curriculum designed to help students understand the fundamentals of computer networks through practical exercises. The goal of the project is to configure small network scenarios by correctly assigning IP addresses, subnet masks, and routing rules so that all devices can communicate with each other.

The project is completed using an interactive training interface where multiple levels simulate different network topologies. Each level introduces new challenges, such as subnetting, routing through gateways, and ensuring connectivity across segmented networks.

By completing NetPractice, students gain a solid understanding of essential networking concepts and how they are applied in real-world scenarios.

## Instructions

### Running the Training Interface

To start the NetPractice training interface, follow these steps:

```bash
chmod +x run.sh
./run.sh
```

This will launch the interactive environment in your browser or local interface, depending on your setup.

---

### How to Use the Interface

* Each level presents a network diagram with hosts, routers, and switches.
* Your task is to:
  * Assign valid IP addresses
  * Configure subnet masks
  * Set correct default gateways
* Once the configuration is correct, the system will validate connectivity.

---

### Exporting Configurations

After successfully completing a level:

1. Use the **“Export”** button in the interface.
2. Save the generated configuration file.
3. Ensure each file corresponds to its level (e.g., `level1`, `level2`, etc.).

---

### Submission Requirements

* You must submit **10 configuration files**, one for each level.
* All exported files must be placed **at the root of your Git repository**.
* File naming should clearly reflect the corresponding level.

---

## Features

* Interactive network simulation
* Progressive difficulty across 10 levels
* Real-world networking scenarios
* Immediate validation of configurations

---

## Networking Concepts Covered

This project focuses on core networking principles, including:

* TCP/IP addressing
* Subnet masks and subnetting
* Default gateways
* Routing fundamentals
* Role of routers and switches
* OSI model layers
* Network segmentation and communication

---

## Resources

### Documentation & Learning Materials

* RFC 791 – Internet Protocol
* RFC 793 – Transmission Control Protocol
* Cisco Networking Basics documentation
* Subnetting tutorials (e.g., practical subnetting guides)
* OSI Model explanations and networking fundamentals courses

### Suggested Tutorials

* Introduction to TCP/IP networking
* Subnetting made easy (CIDR and binary math)
* How routers and switches work
* Understanding packet flow in a network

---

### Use of AI

AI tools were used in this project to assist in structuring documentation (including this README)

All configurations and solutions were implemented and validated manually through the NetPractice interface.

---

## Additional Notes

NetPractice is less about memorization and more about understanding how networks behave. Taking time to analyze each level and test configurations is key to mastering the concepts.

---

## Repository Structure

```
.
├── level1
├── level2
├── level3
├── level4
├── level5
├── level6
├── level7
├── level8
├── level9
├── level10
└── README.md
```

---

## Conclusion

This project provides a strong foundation in networking by combining theory with practical application. It prepares students for more advanced topics in system administration, cybersecurity, and distributed systems.
