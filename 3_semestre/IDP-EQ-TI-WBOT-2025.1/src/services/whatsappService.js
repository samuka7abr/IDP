const axios = require('axios');
const config = require('../config');
const logger = require('../utils/logger');

/**
 * Envia uma mensagem utilizando a API do WhatsApp.
 *
 * @param {string} recipient - Identificador do destinatário (ex: número de telefone)
 * @param {string} text - Texto da mensagem a ser enviada
 * @returns {Promise<Object>} - Dados de resposta da API
 */
exports.sendMessage = async (recipient, text) => {
  try {
    const response = await axios.post(`${config.whatsappApiUrl}/send`, {
      to: recipient,
      message: text,
      apiKey: config.whatsappApiKey
    });
    logger.log("Message sent successfully: " + JSON.stringify(response.data));
    return response.data;
  } catch (error) {
    logger.log("Error sending message: " + error.message);
    throw error;
  }
};
