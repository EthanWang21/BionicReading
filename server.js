const express = require('express');
const bodyParser = require('body-parser');
const { spawnSync } = require('child_process');

const app = express();
const port = 3000;

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

// Serve static files from the public directory
app.use(express.static('public'));

app.post('/applyBionicReadingFilter', (req, res) => {
    const inputData = req.body.inputData;

    // Run the C++ program as a child process
    const result = spawnSync('./bionic_reading_filter', { input: inputData });

    if (result.error) {
        console.error('Error executing bionic_reading_filter:', result.error);
        res.status(500).send('Internal Server Error');
        return;
    }

    // Send the modified text back to the client
    res.send(result.stdout.toString());
});

app.listen(port, () => {
    console.log(`Server is listening at http://localhost:${port}`);
});