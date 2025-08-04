import React from 'react'
import NewsGrid from '../Components/NewsGrid';
import { news } from '../Utils/mocks/news';

function News() {
  return (
        <div className="app">
          <NewsGrid news={news} />
        </div>
  )
}

export default News