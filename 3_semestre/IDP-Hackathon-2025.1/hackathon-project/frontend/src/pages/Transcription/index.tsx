import { useState, useRef, useEffect } from 'react';
import styled from 'styled-components';
import { FaMicrophone } from 'react-icons/fa';
import { useParams } from 'react-router-dom';

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

const TranscriptionForm = styled.form`
  background: ${({ theme }) => theme.colors.white};
  padding: 2rem;
  border-radius: 8px;
  box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
`;

const InputGroup = styled.div`
  margin-bottom: 1.5rem;
`;

const Label = styled.label`
  display: block;
  margin-bottom: 0.5rem;
  color: ${({ theme }) => theme.colors.text};
`;

const Input = styled.input`
  width: 100%;
  padding: 0.75rem;
  border: 1px solid ${props => props.theme.colors.gray[300]};
  border-radius: 4px;
  font-size: 1rem;
`;

const TextArea = styled.textarea`
  width: 100%;
  padding: 0.75rem;
  border: 1px solid ${props => props.theme.colors.gray[300]};
  border-radius: 4px;
  font-size: 1rem;
  min-height: 150px;
  resize: vertical;
`;

const ButtonGroup = styled.div`
  display: flex;
  gap: 1rem;
  margin-top: 1rem;
`;

const Button = styled.button`
  padding: 0.75rem 1.5rem;
  border: none;
  border-radius: 4px;
  font-size: 1rem;
  cursor: pointer;
  display: flex;
  align-items: center;
  gap: 0.5rem;
  background: ${props => props.theme.colors.primary};
  color: white;
  transition: opacity 0.2s;

  &:hover {
    opacity: 0.9;
  }
`;

const MicrophoneButton = styled(Button)`
  background: ${props => props.theme.colors.secondary};
`;

const DragDropArea = styled.div`
  border: 2px dashed ${({ theme }) => theme.colors.primary};
  border-radius: 8px;
  padding: 2rem;
  text-align: center;
  color: ${({ theme }) => theme.colors.text};
  background: ${({ theme }) => theme.colors.gray[100]};
  margin-bottom: 1.5rem;
  cursor: pointer;
  transition: background 0.2s, border-color 0.2s;
  &:hover, &.dragover {
    background: ${({ theme }) => theme.colors.gray[200]};
    border-color: ${({ theme }) => theme.colors.secondary};
  }
`;

const formatDate = (dateStr: string) => {
  const [year, month, day] = dateStr.split('-');
  return `${day.padStart(2, '0')}/${month.padStart(2, '0')}/${year}`;
};

export function Transcription() {
  const { patientName } = useParams<{ patientName: string }>();
  const [date, setDate] = useState('');
  const [time, setTime] = useState('');
  const [transcription, setTranscription] = useState('');
  const [isRecording, setIsRecording] = useState(false);
  const [recordingTime, setRecordingTime] = useState(0);
  const intervalRef = useRef<any>(null);
  const [uploadedFiles, setUploadedFiles] = useState<File[]>([]);
  const [isDragOver, setIsDragOver] = useState(false);
  const fileInputRef = useRef<HTMLInputElement | null>(null);
  const [transcriptions, setTranscriptions] = useState<any[]>([]);

  // Carregar transcrições do localStorage ao abrir
  useEffect(() => {
    if (patientName) {
      const stored = localStorage.getItem(`transcriptions_${patientName}`);
      if (stored) setTranscriptions(JSON.parse(stored));
    }
  }, [patientName]);

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (!date || !time || !transcription) return;
    const formattedDate = formatDate(date);
    const newTranscription = {
      date: formattedDate,
      time,
      transcription,
      files: uploadedFiles.map(f => f.name),
      createdAt: new Date().toISOString(),
    };
    const updated = [...transcriptions, newTranscription];
    setTranscriptions(updated);
    if (patientName) {
      localStorage.setItem(`transcriptions_${patientName}`, JSON.stringify(updated));
      // Atualizar sessões também
      const sessionsRaw = localStorage.getItem('sessions');
      let sessions = sessionsRaw ? JSON.parse(sessionsRaw) : {};
      // Encontrar o id do paciente pelo nome (buscando nos clients)
      const clientsRaw = localStorage.getItem('clients');
      let clientId = null;
      if (clientsRaw) {
        const clients = JSON.parse(clientsRaw);
        const found = clients.find((c: any) => c.name === patientName);
        if (found) clientId = found.id;
      }
      if (clientId) {
        if (!sessions[clientId]) sessions[clientId] = [];
        sessions[clientId].push({
          id: Date.now(),
          date: formattedDate,
          time,
          notes: transcription,
        });
        localStorage.setItem('sessions', JSON.stringify(sessions));
      }
    }
    setDate('');
    setTime('');
    setTranscription('');
    setUploadedFiles([]);
    alert('Transcrição salva com sucesso!');
  };

  const toggleRecording = () => {
    if (!isRecording) {
      setIsRecording(true);
      setRecordingTime(0);
      intervalRef.current = setInterval(() => {
        setRecordingTime((prev) => prev + 1);
      }, 1000);
    } else {
      setIsRecording(false);
      if (intervalRef.current) {
        clearInterval(intervalRef.current);
        intervalRef.current = null;
      }
    }
    // TODO: Implementar lógica de gravação
  };

  // Formatar tempo em mm:ss
  const formatTime = (seconds: number) => {
    const min = Math.floor(seconds / 60).toString().padStart(2, '0');
    const sec = (seconds % 60).toString().padStart(2, '0');
    return `${min}:${sec}`;
  };

  // Drag and drop handlers
  const handleDrop = (e: React.DragEvent<HTMLDivElement>) => {
    e.preventDefault();
    setIsDragOver(false);
    if (e.dataTransfer.files && e.dataTransfer.files.length > 0) {
      setUploadedFiles(Array.from(e.dataTransfer.files));
    }
  };
  const handleDragOver = (e: React.DragEvent<HTMLDivElement>) => {
    e.preventDefault();
    setIsDragOver(true);
  };
  const handleDragLeave = () => setIsDragOver(false);
  const handleFileChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    if (e.target.files && e.target.files.length > 0) {
      setUploadedFiles(Array.from(e.target.files));
    }
  };

  return (
    <Container>
      <Header>
        <Title>Transcrição de Consulta - {patientName}</Title>
      </Header>

      <TranscriptionForm onSubmit={handleSubmit}>
        <InputGroup>
          <Label>Data da Consulta</Label>
          <Input
            type="date"
            value={date}
            onChange={(e) => setDate(e.target.value)}
            required
          />
        </InputGroup>

        <InputGroup>
          <Label>Horário</Label>
          <Input
            type="time"
            value={time}
            onChange={(e) => setTime(e.target.value)}
            required
          />
        </InputGroup>

        <InputGroup>
          <Label>Transcrição</Label>
          <TextArea
            value={transcription}
            onChange={(e) => setTranscription(e.target.value)}
            placeholder="Digite ou grave a transcrição da consulta..."
            required
          />
        </InputGroup>

        <DragDropArea
          className={isDragOver ? 'dragover' : ''}
          onDrop={handleDrop}
          onDragOver={handleDragOver}
          onDragLeave={handleDragLeave}
          onClick={() => fileInputRef.current?.click()}
        >
          Arraste e solte arquivos aqui ou clique para selecionar
          <input
            type="file"
            multiple
            ref={fileInputRef}
            style={{ display: 'none' }}
            onChange={handleFileChange}
          />
        </DragDropArea>
        {uploadedFiles.length > 0 && (
          <ul style={{ marginBottom: '1.5rem', textAlign: 'left' }}>
            {uploadedFiles.map((file, idx) => (
              <li key={idx}>{file.name}</li>
            ))}
          </ul>
        )}

        <ButtonGroup>
          <Button type="submit">Salvar Transcrição</Button>
          <MicrophoneButton type="button" onClick={toggleRecording}>
            <FaMicrophone />
            {isRecording ? 'Parar Gravação' : 'Iniciar Gravação'}
            {isRecording && (
              <span style={{ marginLeft: '0.5rem', fontWeight: 'bold' }}>{formatTime(recordingTime)}</span>
            )}
          </MicrophoneButton>
        </ButtonGroup>
      </TranscriptionForm>
    </Container>
  );
} 