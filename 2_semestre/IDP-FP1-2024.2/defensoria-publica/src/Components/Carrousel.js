import React, { useState } from 'react';
import Slider from 'react-slick';
import { personas } from '../Utils/mocks/persona';
import "slick-carousel/slick/slick.css"; 
import "slick-carousel/slick/slick-theme.css";
import "../Style/Components/carrousel.css"; // Certifique-se de criar e estilizar este arquivo CSS
import "../Style/Components/teste.css"
import { Button, Card, Container, Typography } from '@mui/material';
import Orientation from './Orientations';

function Carrousel() {
  const [sliderRef, setSliderRef] = useState(null);
  const [showPopup, setShowPopup] = useState(false);
  const [currentPersona, setCurrentPersona] = useState(null);

  const settings = {
    dots: false,
    infinite: true,
    speed: 500,
    slidesToShow: 1,
    slidesToScroll: 1,
    beforeChange: (current, next) => setCurrentPersona(personas[next]),
  };

  const handleNext = () => {
    if (sliderRef) {
      sliderRef.slickNext();
    }
  };

  const handlePopup = () => {
    setShowPopup(true);
  };

  const closePopup = () => {
    setShowPopup(false);
  };

  return (
    <div className="carousel">
      <Slider ref={setSliderRef} {...settings}>
        {personas.map((elementoDoArray, index) => {
          const { name, personaHistory, srcImage } = elementoDoArray;
          return (
            <Card sx={{ display: "flex" }} className='body_container' key={index}>
            <Container component="div" className='container'>
      <div className='character' style={{ display: 'flex', flexDirection: 'column', height: "40%" }}>
      <img src={srcImage} alt='guy' style={{ width: "30vw", height: "60vh" }}></img>
      </div>
      <div className='speech-bubble'>
      <Typography> { `Me chamo ${name}, ${personaHistory}` } </Typography>
      </div>
    </Container>
        <div className='options carousel-buttons'>
        <Button onClick={handleNext} className="secondary" >Não parece o meu problema!</Button>
        <Button onClick={() => { setCurrentPersona(elementoDoArray); handlePopup(); }}>
    Me parece o meu problema!
</Button>
        </div>
            </Card>
          );
        })}
      </Slider>
      {showPopup && currentPersona && <Orientation currentPersona={currentPersona} closePopup={closePopup}/>}
    </div>
  );
}

export default Carrousel;
