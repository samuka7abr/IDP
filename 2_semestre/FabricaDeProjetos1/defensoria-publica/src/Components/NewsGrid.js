import React from 'react';
import NewsCard from './NewsCard'; // Componente separado para o card
import '../Style/Components/NewsGrid.css';

const NewsGrid = ({ news }) => {
  return (
    <div className="news-grid">
      {news.map((item, index) => (
        <NewsCard 
          key={index} 
          title={item.title} 
          summary={item.summary} 
          image={item.srcImg} 
        />
      ))}
    </div>
  );
};

export default NewsGrid;
