import { BrowserRouter as Router, Routes, Route, Navigate } from 'react-router-dom'
import { ThemeProvider } from 'styled-components'
import { GlobalStyle } from './styles/global'
import { defaultTheme, darkTheme } from './styles/themes'
import { Home } from './pages/Home'
import { Login } from './pages/Login'
import { Transcription } from './pages/Transcription'
import { Sessions } from './pages/Sessions'
import { useState, useEffect } from 'react';

function App() {
  const [isDark, setIsDark] = useState(() => {
    const stored = localStorage.getItem('theme');
    return stored ? stored === 'dark' : false;
  });
  useEffect(() => {
    localStorage.setItem('theme', isDark ? 'dark' : 'light');
  }, [isDark]);
  const toggleTheme = () => setIsDark((prev) => !prev);

  return (
    <ThemeProvider theme={isDark ? darkTheme : defaultTheme}>
      <Router>
        <GlobalStyle />
        <Routes>
          <Route path="/login" element={<Login />} />
          <Route path="/home" element={<Home showThemeToggle isDark={isDark} toggleTheme={toggleTheme} />} />
          <Route path="/sessions/:patientName" element={<Sessions />} />
          <Route path="/transcription/:patientName" element={<Transcription />} />
          <Route path="/" element={<Navigate to="/login" replace />} />
        </Routes>
      </Router>
    </ThemeProvider>
  )
}

export default App
