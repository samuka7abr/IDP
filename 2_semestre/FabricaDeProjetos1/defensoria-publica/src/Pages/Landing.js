import React, { useState, useEffect } from 'react';
import axios from 'axios';
import { useNavigate } from 'react-router-dom';

function Landing({ setSuburb, setCity, city }) {
  const [location, setLocation] = useState({ latitude: null, longitude: null });
  const navigate = useNavigate();

  useEffect(() => {
    if (navigator.geolocation) {
      navigator.geolocation.getCurrentPosition(
        (position) => {
          const { latitude, longitude } = position.coords;
          setLocation({ latitude, longitude });

          const apiKey = 'f11d3bf2ac824cba99b0ccb7cfd8c083';
          const url = `https://api.opencagedata.com/geocode/v1/json?q=${latitude}+${longitude}&key=${apiKey}`;

          axios.get(url)
            .then(response => {
              const city = response.data.results[0].components.city;
              const suburb = response.data.results[0].components.suburb;
              console.log(response.data.results[0]);

              setCity(city);
              setSuburb(suburb); // Atualize o estado suburb no componente Root
            })
            .catch(error => {
              console.error("Erro ao obter o nome da cidade: ", error);
            });
        },
        (error) => {
          console.error("Erro ao obter localização: ", error);
        }
      );
    } else {
      console.error("Geolocalização não é suportada pelo navegador.");
    }
  }, [setSuburb]);

  useEffect(() => {
    if (city !== '') {
      navigate('/home');
    }
  }, [city, navigate]);

  return (
    <div>
      <h1>Localização do Usuário</h1>
      {location.latitude && location.longitude ? (
        <div>
          <p>Cidade: {city || 'Obtendo nome da cidade...'}</p>
        </div>
      ) : (
        <p>Obtendo localização...</p>
      )}
    </div>
  );
}

export default Landing;
