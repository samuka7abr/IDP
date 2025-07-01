import React, { useState } from "react";
import { Box, Button, Typography, Dialog, DialogContent } from "@mui/material";
import { motion } from "framer-motion";
import CarretaImg from "../Style/Icons/CarretaDefensoria.jpg";
import { carretaInfo } from "../Utils/mocks/carreta";
import "../Style/Components/carreta.css";

const carretaYoutube = `https://www.youtube.com/embed/7WZCgCaB_QA?autoplay=1`;

function CarretaPop({ onClose }) {
  const [showInfo, setShowInfo] = useState(false); // Controla o estado do pop-up de informações
  const [showPopup, setShowPopup] = useState(true); // Controla o estado do pop-up principal

  // Função para fechar o pop-up
  const handleClose = () => {
    setShowPopup(false);
    setShowInfo(false);
  };

  const handleCloseInfo = () => {
    setShowInfo(false);
  };

  return (
    <>
      <div className="overlay"></div> {/* Camada de fundo */}
      {showPopup && (
        <motion.div
          className="pop-up-container"
          initial="pop-up-enter"
          animate="pop-up-enter-active"
          exit="pop-up-exit"
          variants={{
            "pop-up-enter": {
              x: "100%", // Começa fora da tela à direita
            },
            "pop-up-enter-active": {
              x: "0%", // Fica centralizado
            },
            "pop-up-exit": {
              x: "50%",
            },
            "pop-up-exit-active": {
              x: "100%", // Sai para a direita
            },
          }}
          style={{
            position: "fixed",
            zIndex: 1000,
            backgroundColor: "#fff",
            boxShadow: "0 5px 15px rgba(0, 0, 0, 0.3)",
            borderRadius: "10px",
            overflow: "hidden",
            width: "100%",
            maxWidth: "800px",
          }}
        >
          <Box sx={{ position: "relative", textAlign: "center" }}>
            <img
              src={CarretaImg}
              alt="Carreta Defensoria"
              style={{ width: "100%", height: "auto" }}
            />
            <iframe
              src={`https://www.youtube.com/embed/7WZCgCaB_QA?autoplay=1&controls=0`}
              title="Carreta Defensoria"
              style={{ width: "100%", height: "300px", marginTop: "10px" }}
              allow="autoplay; encrypted-media"
            ></iframe>


          </Box>
          <Box sx={{ p: 3, textAlign: "center" }}>
            <Button
              variant="contained"
              color="primary"
              onClick={() => setShowInfo(true)}
              sx={{ mr: 2 }}
            >
              Saiba Mais
            </Button>
            <Button variant="outlined" color="secondary" onClick={onClose}>
              Fechar
            </Button>
          </Box>
        </motion.div>
      )}

      {/* Modal de informações */}
      <Dialog open={showInfo} onClose={handleClose} maxWidth="md" fullWidth>
        <DialogContent>
          <Typography variant="h6" gutterBottom>
            Informações da Carreta Defensoria
          </Typography>
          <Typography variant="body1" sx={{ whiteSpace: "pre-line" }}>
            {carretaInfo}
          </Typography>
          <Box sx={{ textAlign: "center", mt: 3 }}>
            <Button variant="contained" color="secondary" onClick={handleCloseInfo}>
              Fechar
            </Button>
          </Box>
        </DialogContent>
      </Dialog>
    </>
  );
}

export default CarretaPop;
