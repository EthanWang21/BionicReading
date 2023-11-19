Bionic Reading Filter Project

Overview
The Bionic Reading Filter project is a web application that facilitates a reading method known as Bionic Reading. This method guides the eyes through text using artificial fixation points, allowing the reader to focus on highlighted initial letters and letting the brain center complete the word. The application aims to encourage a more in-depth reading and understanding of written content.

Project Structure
Frontend (public folder)
BionicReader.js: JavaScript file containing the implementation of the BionicReader class. This class handles the application of the Bionic Reading filter, changing bold colors, and toggling dark mode.

index.html: HTML file representing the main structure of the web page. It includes input areas, buttons for applying the filter, changing colors, toggling dark mode, and a section to display the filtered text. It also provides a font size slider for adjusting the text size.

styles.css: CSS file defining the styles for the HTML elements, including the appearance of the text, buttons, and the results container.

Backend (BionicReading folder)
BionicReader.cpp: C++ file implementing the BionicReader class. This class provides functions for cleaning and applying the Bionic Reading filter to text.

BionicReader.h: Header file declaring the BionicReader class and its member functions.

BionicReadingFilter.cpp: C++ file containing the main function that reads input text, applies the Bionic Reading filter using the BionicReader class, and outputs the modified text.

server.js: Node.js server file using Express to handle HTTP requests. It serves static files from the public directory and processes POST requests to apply the Bionic Reading filter.

Getting Started

Navigate to the project directory:
cd BionicReading

In a Linux environment, run the server:
./server

Open your web browser and visit http://localhost:3000 to access the Bionic Reading Filter application.

Usage
Enter text into the input area.

Click the "Apply Bionic Reading Filter" button to apply the Bionic Reading filter.

Use the "Change Bold Color" button to modify the color of the boldened part.

Toggle dark mode on/off with the "Toggle Dark Mode" button.

Adjust the font size using the font size slider.

If you encounter any issues or have suggestions for improvement, please let me know.