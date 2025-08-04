import { useState, useEffect } from 'react';
import styled from 'styled-components';
import { FiPlus, FiTrash2, FiEdit2 } from 'react-icons/fi';
import { useParams, useNavigate } from 'react-router-dom';
import React from 'react';

const Container = styled.div`
  padding: 2rem;
  max-width: 1200px;
  margin: 0 auto;
`;

const Header = styled.div`
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 2rem;
`;

const Title = styled.h1`
  color: ${props => props.theme.colors.primary};
`;

const AddButton = styled.button`
  background: ${props => props.theme.colors.primary};
  color: white;
  padding: 0.75rem 1.5rem;
  border: none;
  border-radius: 4px;
  font-size: 1rem;
  cursor: pointer;
  display: flex;
  align-items: center;
  gap: 0.5rem;
  transition: opacity 0.2s;

  &:hover {
    opacity: 0.9;
  }
`;

const SessionsGrid = styled.div`
  display: grid;
  grid-template-columns: repeat(auto-fill, minmax(300px, 1fr));
  gap: 1.5rem;
  margin-top: 2rem;
`;

const SessionCard = styled.div`
  background: ${({ theme }) => theme.colors.white};
  padding: 1.5rem;
  border-radius: 8px;
  box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
  transition: transform 0.2s;
  color: ${({ theme }) => theme.colors.text};

  &:hover {
    transform: translateY(-2px);
  }
`;

const SessionDate = styled.h3`
  color: ${({ theme }) => theme.colors.text};
  margin-bottom: 0.5rem;
`;

const SessionTime = styled.p`
  color: ${({ theme }) => theme.colors.text};
  font-size: 0.875rem;
  margin-bottom: 1rem;
`;

const SessionNotes = styled.p`
  color: ${({ theme }) => theme.colors.text};
  font-size: 0.875rem;
  line-height: 1.5;
`;

const RemoveButton = styled.button`
  background: none;
  border: none;
  color: ${({ theme }) => theme.colors.error};
  cursor: pointer;
  font-size: 1.2rem;
  float: right;
  margin-left: 0.5rem;
  transition: color 0.2s;
  &:hover {
    color: #b71c1c;
  }
`;

const EditButton = styled.button`
  background: none;
  border: none;
  color: ${({ theme }) => theme.colors.primary};
  cursor: pointer;
  font-size: 1.2rem;
  float: right;
  margin-left: 0.5rem;
  transition: color 0.2s;
  &:hover {
    color: ${({ theme }) => theme.colors.secondary};
  }
`;

interface Session {
  id: number;
  date: string;
  time: string;
  notes: string;
}

export function Sessions() {
  const { patientName } = useParams<{ patientName: string }>();
  const navigate = useNavigate();
  const [sessions, setSessions] = useState<Session[]>([]);
  const [editingSession, setEditingSession] = useState<Session | null>(null);
  const [editDate, setEditDate] = useState('');
  const [editTime, setEditTime] = useState('');
  const [editNotes, setEditNotes] = useState('');

  useEffect(() => {
    // Buscar id do paciente pelo nome
    const clientsRaw = localStorage.getItem('clients');
    let clientId = null;
    if (clientsRaw && patientName) {
      const clients = JSON.parse(clientsRaw);
      const found = clients.find((c: any) => c.name === patientName);
      if (found) clientId = found.id;
    }
    // Buscar sessões desse paciente
    if (clientId) {
      const sessionsRaw = localStorage.getItem('sessions');
      if (sessionsRaw) {
        const allSessions = JSON.parse(sessionsRaw);
        setSessions(allSessions[clientId] || []);
        return;
      }
    }
    // Se não encontrar, mantém vazio
    setSessions([]);
  }, [patientName]);

  const handleAddSession = () => {
    navigate(`/transcription/${encodeURIComponent(patientName || '')}`);
  };

  const handleRemoveSession = (sessionId: number) => {
    if (!window.confirm('Tem certeza que deseja remover esta sessão?')) return;
    // Buscar id do paciente pelo nome
    const clientsRaw = localStorage.getItem('clients');
    let clientId = null;
    if (clientsRaw && patientName) {
      const clients = JSON.parse(clientsRaw);
      const found = clients.find((c: any) => c.name === patientName);
      if (found) clientId = found.id;
    }
    if (clientId) {
      const sessionsRaw = localStorage.getItem('sessions');
      if (sessionsRaw) {
        const allSessions = JSON.parse(sessionsRaw);
        const updated = (allSessions[clientId] || []).filter((s: any) => s.id !== sessionId);
        allSessions[clientId] = updated;
        localStorage.setItem('sessions', JSON.stringify(allSessions));
        setSessions(updated);
      }
    }
  };

  // Função para abrir o modal de edição
  const handleEditSession = (session: Session) => {
    setEditingSession(session);
    // Converter data para formato yyyy-MM-dd para o input type="date"
    const [day, month, year] = session.date.split('/');
    setEditDate(`${year}-${month.padStart(2, '0')}-${day.padStart(2, '0')}`);
    setEditTime(session.time);
    setEditNotes(session.notes);
  };

  // Função para salvar a edição
  const handleSaveEdit = () => {
    if (!editingSession) return;
    // Formatar data para dd/MM/yyyy
    const [year, month, day] = editDate.split('-');
    const formattedDate = `${day.padStart(2, '0')}/${month.padStart(2, '0')}/${year}`;
    const updatedSession = {
      ...editingSession,
      date: formattedDate,
      time: editTime,
      notes: editNotes,
    };
    // Atualizar no localStorage
    const clientsRaw = localStorage.getItem('clients');
    let clientId = null;
    if (clientsRaw && patientName) {
      const clients = JSON.parse(clientsRaw);
      const found = clients.find((c: any) => c.name === patientName);
      if (found) clientId = found.id;
    }
    if (clientId) {
      const sessionsRaw = localStorage.getItem('sessions');
      if (sessionsRaw) {
        const allSessions = JSON.parse(sessionsRaw);
        const updated = (allSessions[clientId] || []).map((s: Session) =>
          s.id === editingSession.id ? updatedSession : s
        );
        allSessions[clientId] = updated;
        localStorage.setItem('sessions', JSON.stringify(allSessions));
        setSessions(updated);
      }
    }
    setEditingSession(null);
  };

  return (
    <Container>
      <Header>
        <Title>Sessões - {patientName}</Title>
        <AddButton onClick={handleAddSession}>
          <FiPlus />
          Nova Sessão
        </AddButton>
      </Header>

      <SessionsGrid>
        {sessions.map(session => (
          <SessionCard key={session.id}>
            <RemoveButton title="Remover sessão" onClick={() => handleRemoveSession(session.id)}>
              <FiTrash2 />
            </RemoveButton>
            <EditButton title="Editar sessão" onClick={() => handleEditSession(session)}>
              <FiEdit2 />
            </EditButton>
            <SessionDate>{session.date}</SessionDate>
            <SessionTime>{session.time}</SessionTime>
            <SessionNotes>{session.notes}</SessionNotes>
          </SessionCard>
        ))}
      </SessionsGrid>

      {/* Modal de edição */}
      {editingSession && (
        <div style={{
          position: 'fixed',
          top: 0,
          left: 0,
          width: '100vw',
          height: '100vh',
          background: 'rgba(0,0,0,0.5)',
          display: 'flex',
          alignItems: 'center',
          justifyContent: 'center',
          zIndex: 1000
        }}
          onClick={() => setEditingSession(null)}
        >
          <div style={{
            background: '#222',
            color: '#fff',
            borderRadius: 8,
            padding: 32,
            minWidth: 320,
            maxWidth: 400,
            boxShadow: '0 2px 8px rgba(0,0,0,0.2)'
          }}
            onClick={e => e.stopPropagation()}
          >
            <h2>Editar Sessão</h2>
            <div style={{ marginBottom: 16 }}>
              <label>Data</label>
              <input
                type="date"
                value={editDate}
                onChange={e => setEditDate(e.target.value)}
                style={{ width: '100%', padding: 8, borderRadius: 4, border: '1px solid #ccc', marginTop: 4 }}
              />
            </div>
            <div style={{ marginBottom: 16 }}>
              <label>Horário</label>
              <input
                type="time"
                value={editTime}
                onChange={e => setEditTime(e.target.value)}
                style={{ width: '100%', padding: 8, borderRadius: 4, border: '1px solid #ccc', marginTop: 4 }}
              />
            </div>
            <div style={{ marginBottom: 16 }}>
              <label>Anotações</label>
              <textarea
                value={editNotes}
                onChange={e => setEditNotes(e.target.value)}
                style={{ width: '100%', padding: 8, borderRadius: 4, border: '1px solid #ccc', marginTop: 4, minHeight: 80 }}
              />
            </div>
            <button
              onClick={handleSaveEdit}
              style={{ background: '#4f8cff', color: '#fff', border: 'none', borderRadius: 4, padding: '8px 16px', cursor: 'pointer', marginRight: 8 }}
            >
              Salvar
            </button>
            <button
              onClick={() => setEditingSession(null)}
              style={{ background: '#888', color: '#fff', border: 'none', borderRadius: 4, padding: '8px 16px', cursor: 'pointer' }}
            >
              Cancelar
            </button>
          </div>
        </div>
      )}
    </Container>
  );
} 