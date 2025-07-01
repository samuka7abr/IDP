import React from "react";
import { programas } from "../Utils/mocks/programas";
import '../Style/Components/Programas.css'; 
function Programas() {
  return (
    <div className="programas-container">
  {programas.map((programa) => (
    <div key={programa.id} className="programa-item">
      <img
        src={programa.srcImage}
        alt={programa.name}
        className="programa-image"
      />
      <div className="programa-name">{programa.name}</div>
    </div>
  ))}
</div>
  );
}

export default Programas;
