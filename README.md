# Simple Python Chat App

A basic command-line chat application written in Python using sockets for communication between a server and multiple clients.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Running the Server](#running-the-server)
  - [Running the Clients](#running-the-clients)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Overview

This is a simple chat application that allows multiple users to connect to a central server and exchange text messages in real-time. The server listens for incoming connections, while the clients can send and receive messages.

## Features

- Multiple clients can connect to the server simultaneously.
- Messages sent by one client are broadcasted to all connected clients.
- Basic error handling.

### Prerequisites

Before running the chat application, make sure you have Python installed on your machine.

### Running the Server

1. Open a terminal.
2. Navigate to the directory containing `server.py`.
3. Run the server using the following command:

   ```bash
   python server.py
The server will begin listening for incoming connections.

### Starting one or more clients

1. Open one or more additional terminals.
2. Navigate to the directory containing client.py.
3. Run the client(s) using the following command:

   ```bash
   python client.py
Each client terminal will connect to the server, and you can start typing and sending messages.

### Usage
1. Start the server and multiple client terminals as described in the "Running the Server" and "Running the Clients" sections.
2. Type messages in the client terminals and press Enter to send them.
3. Messages sent by one client will be broadcasted to all connected clients.
4. To exit a client, simply close its terminal. The server will continue running until you manually stop it.
