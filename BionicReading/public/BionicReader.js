class BionicReader {
    applyFilter() {
        const inputText = document.getElementById('inputText').value;

        // Make a POST request to the Node.js server
        fetch('http://localhost:3000/applyBionicReadingFilter', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ inputData: inputText }),
        })
        .then(response => response.text())
        .then(data => {
            // Convert ANSI escape codes to HTML tags
            const htmlContent = data.replace(/\033\[1m/g, '<span class="customBold">')
                                   .replace(/\033\[0m/g, '</span>');

            // Insert a line break every 6 words
            const words = htmlContent.split(/\s+/);
            const wordsWithLineBreaks = words.map((word, index) => (index > 0 && index % 12 === 0) ? '<br>' + word : word);
            const modifiedText = wordsWithLineBreaks.join(' ');

            // Get font size from the slider input
            const fontSize = document.getElementById('fontSizeSlider').value;

            // Display the modified text with updated font size
            const filteredTextElement = document.getElementById('filteredText');
            filteredTextElement.innerHTML = modifiedText;
            filteredTextElement.style.fontSize = `${fontSize}px`;
        })
        .catch(error => console.error('Error:', error));
    }

    changeColor() {
        const colorPicker = document.getElementById('colorPicker');
        const newColor = colorPicker.value;

        // Update the color of all elements with the customBold class
        const boldElements = document.getElementsByClassName('customBold');
        Array.from(boldElements).forEach(element => {
            element.style.color = newColor;
        });
    }

    toggle() {
        var element = document.body;
        element.classList.toggle("darkMode");
    }
    
}

const bionicReader = new BionicReader();
