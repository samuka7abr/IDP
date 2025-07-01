const express = require('express');
const dotenv = require('dotenv');

dotenv.config();

const webhookRoutes = require('./routes/webhook');

const app = express();
const PORT = process.env.PORT || 3000;

app.use(express.json());

app.use('/webhook', webhookRoutes);

app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
