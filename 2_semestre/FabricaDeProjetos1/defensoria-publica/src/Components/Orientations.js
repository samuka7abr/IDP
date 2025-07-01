import React from "react";
import { Button, Card, Typography, Box, Divider, List, ListItem, ListItemText } from '@mui/material';
import { Orientations } from "../Utils/mocks/orientation";

function Orientation({ currentPersona, closePopup }) {
    if (!currentPersona) return null;

    // Busca a persona correspondente em Orientations pelo nome
    const matchedOrientation = Orientations.find(
        (orientation) => orientation.name === currentPersona.name
    );

    // Se não encontrar correspondência, exibe uma mensagem padrão
    const {
        name = currentPersona.name,
        documents = {},
        options = "Nenhuma opção disponível.",
        adress = []
    } = matchedOrientation || {};

    return (
        <Box
            sx={{
                position: 'fixed',
                top: '50%',
                left: '50%',
                transform: 'translate(-50%, -50%)',
                width: { xs: '90%', sm: '70%' },
                bgcolor: 'background.paper',
                boxShadow: 24,
                p: 4,
                borderRadius: 2,
                maxHeight: '80%',
                overflowY: 'auto',
            }}
        >
            <Typography variant="h4" sx={{ mb: 2, textAlign: "center", fontWeight: "bold" }}>
                Orientações para {name}
            </Typography>
            <Divider sx={{ mb: 2 }} />

            <Typography variant="h6" sx={{ mt: 2, fontWeight: "bold" }}>Documentos Necessários:</Typography>
            {Object.keys(documents).length > 0 ? (
                <List>
                    {Object.entries(documents).map(([key, value], index) => (
                        <ListItem key={index}>
                            <ListItemText
                                primary={key}
                                secondary={value}
                            />
                        </ListItem>
                    ))}
                </List>
            ) : (
                <Typography variant="body2" color="text.secondary">
                    Nenhum documento especificado.
                </Typography>
            )}

            <Typography variant="h6" sx={{ mt: 3, fontWeight: "bold" }}>Opções de Atendimento:</Typography>
            <Typography variant="body1" sx={{ whiteSpace: 'pre-line', mb: 2 }}>
                {options}
            </Typography>

            <Typography variant="h6" sx={{ mt: 3, fontWeight: "bold" }}>Endereços:</Typography>
            {adress.length > 0 ? (
                <List>
                    {adress.map((addr, index) => (
                        <ListItem key={index}>
                            <ListItemText primary={addr} />
                        </ListItem>
                    ))}
                </List>
            ) : (
                <Typography variant="body2" color="text.secondary">
                    Nenhum endereço disponível.
                </Typography>
            )}

            <Box sx={{ display: 'flex', justifyContent: 'flex-end', mt: 3 }}>
                <Button variant="contained" color="primary" onClick={closePopup}>
                    Fechar
                </Button>
            </Box>
        </Box>
    );
}

export default Orientation;
