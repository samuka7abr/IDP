/**
 * Este arquivo de configuração utiliza variáveis de ambiente definidas no arquivo .env.
 * Caso as variáveis não estejam definidas, ele utiliza os valores padrão informados.
 * 
 * Atualize as variáveis abaixo conforme as instruções da API oficial do WhatsApp ou do seu provedor (ex.: Twilio).
 */

module.exports = {
    // URL base da API do WhatsApp.
    // Exemplo: 'https://graph.facebook.com/v14.0'
    // Atualize este valor para o endpoint correto da API oficial ou do serviço terceirizado que você utilizar.
    whatsappApiUrl: process.env.WHATSAPP_API_URL || 'https://api.whatsapp.com',
  
    // Chave da API do WhatsApp.
    // Esta chave é fornecida pelo WhatsApp (Meta) ou pelo provedor de API.
    // Insira sua chave de API no arquivo .env, por exemplo: WHATSAPP_API_KEY=your_api_key_here
    whatsappApiKey: process.env.WHATSAPP_API_KEY || 'sua-chave-api-aqui',
  
    // ID do número de telefone do WhatsApp Business.
    // Caso a integração necessite do ID associado ao número de telefone, defina-o aqui.
    whatsappPhoneNumberId: process.env.WHATSAPP_PHONE_NUMBER_ID || '',
  
    // URL do Webhook.
    // Esta URL é usada para receber notificações/mensagens enviadas pela API do WhatsApp.
    // Certifique-se de que esta URL seja acessível externamente (ex.: usando ngrok em desenvolvimento).
    webhookUrl: process.env.WEBHOOK_URL || 'http://seu-dominio.com/webhook'
  };
  