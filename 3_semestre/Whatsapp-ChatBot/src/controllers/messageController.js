const logger = require('../utils/logger');

class MessageController {
  constructor() {
    this.sessions = {};
    this.SESSION_TIMEOUT = 10 * 60 * 1000; // 10 minutos
  }

  resetSessionTimeout(userId) {
    if (this.sessions[userId]?.timeoutHandle) {
      clearTimeout(this.sessions[userId].timeoutHandle);
    }
    this.sessions[userId].timeoutHandle = setTimeout(() => {
      logger.log(`Session for ${userId} expired due to inactivity.`);
      delete this.sessions[userId];
    }, this.SESSION_TIMEOUT);
  }

  handleIncomingMessage(req, res) {
    const messageData = req.body;
    const userId = messageData.from;
    const userMessage = messageData.message ? messageData.message.trim().toLowerCase() : '';

    logger.log(`Received message from ${userId}: ${userMessage}`);

    if (userMessage === 'exit') {
      if (this.sessions[userId]) {
        clearTimeout(this.sessions[userId].timeoutHandle);
        delete this.sessions[userId];
      }
      return res.status(200).send({ reply: 'Session ended. Thank you for contacting us!' });
    }

    if (!this.sessions[userId]) {
      this.sessions[userId] = { createdAt: Date.now() };
      this.resetSessionTimeout(userId);
      
      const reply = `Good morning! Welcome to Fish Info & Sales. How can we help you today?
Please choose an option:
1. Talk to an assistant
2. Know more about our brand
3. Hire Service 1
4. Hire Service 2
Type the number or option name.`;
      return res.status(200).send({ reply });
    }

    this.resetSessionTimeout(userId);

    let reply;
    switch (userMessage) {
      case '1':
      case 'talk to an assistant':
        reply = 'Connecting you to an assistant... Please wait.';
        break;
      case '2':
      case 'know more about our brand':
        reply = 'Our brand is dedicated to providing the freshest and highest quality fish using sustainable practices.';
        break;
      case '3':
      case 'hire service 1':
        reply = 'Service 1: We offer personalized fish selection consultations. An expert will contact you shortly.';
        break;
      case '4':
      case 'hire service 2':
        reply = 'Service 2: We provide fish delivery and preparation services. Please share your location for further details.';
        break;
      default:
        reply = `I didn't understand that. Please select one of the options below or type "exit" to end the session:
1. Talk to an assistant
2. Know more about our brand
3. Hire Service 1
4. Hire Service 2`;
    }

    return res.status(200).send({ reply });
  }
}

const messageControllerInstance = new MessageController();
module.exports = {
  handleIncomingMessage: messageControllerInstance.handleIncomingMessage.bind(messageControllerInstance)
};
