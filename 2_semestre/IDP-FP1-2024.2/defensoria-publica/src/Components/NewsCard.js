import React from 'react';
import '../Style/Components/NewsCard.css';

const NewsCard = ({ title, summary, image }) => {
  return (
    <div className="news-card">
      <div className="news-card-image-container">
        <img src={image} alt={title} className="news-card-image" />
      </div>
      <div className="news-card-content">
        <h2 className="news-card-title">{title}</h2>
        <p className="news-card-summary">{summary}</p>
      </div>
    </div>
  );
};

export default NewsCard;
