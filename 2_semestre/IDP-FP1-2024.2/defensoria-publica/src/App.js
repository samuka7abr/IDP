import Carrousel from './Components/Carrousel';
import NavBar from './Components/NavBar';
import Socials from './Pages/Socials';
import Programas from './Components/Programas';
import './Style/App.css';
import { common } from '@mui/material/colors';
import News from './Pages/News'; 
import { useState, useEffect } from 'react';
import CarretaPop from './Components/Carreta';

function App({city, suburb}) {
  console.log(city, suburb);

  const [showCarretaPopup, setShowCarretaPopup] = useState(false); 


  useEffect(() => {
    if (city === 'Brasília') {
      setShowCarretaPopup(true); // Exibe o pop-up se a cidade for Brasília, adaptar caso a carreta esteja em outra cidade.
    }
  }, [city]);
  
  return (
    <div className="App">
      <NavBar />
      <Carrousel />
      <Programas />
      <News />
      <Socials />
      {showCarretaPopup && (
        <CarretaPop
          onClose={() => setShowCarretaPopup(false)}
        />
      )}
    </div>
  );
}

export default App;
