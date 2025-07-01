import styled from 'styled-components'
import { FiX, FiCalendar, FiClock, FiFileText } from 'react-icons/fi'

interface Session {
  id: number
  date: string
  time: string
  notes: string
}

interface ClientHistoryModalProps {
  isOpen: boolean
  onClose: () => void
  clientName: string
  sessions: Session[]
}

const Overlay = styled.div`
  position: fixed;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background: rgba(0, 0, 0, 0.5);
  display: flex;
  align-items: center;
  justify-content: center;
  padding: ${({ theme }) => theme.spacing.xl};
  z-index: 1000;
`

const Modal = styled.div`
  background: ${({ theme }) => theme.colors.white};
  border-radius: ${({ theme }) => theme.borderRadius.lg};
  padding: ${({ theme }) => theme.spacing.xl};
  width: 100%;
  max-width: 600px;
  max-height: 80vh;
  overflow-y: auto;
  position: relative;
`

const CloseButton = styled.button`
  position: absolute;
  top: ${({ theme }) => theme.spacing.md};
  right: ${({ theme }) => theme.spacing.md};
  background: none;
  border: none;
  color: ${({ theme }) => theme.colors.gray[500]};
  font-size: ${({ theme }) => theme.fonts.sizes.large};
  cursor: pointer;
  padding: ${({ theme }) => theme.spacing.xs};
  border-radius: ${({ theme }) => theme.borderRadius.sm};
  transition: all 0.2s;

  &:hover {
    color: ${({ theme }) => theme.colors.error};
    background: ${({ theme }) => theme.colors.gray[100]};
  }
`

const Title = styled.h2`
  color: ${({ theme }) => theme.colors.text};
  font-size: ${({ theme }) => theme.fonts.sizes.xlarge};
  margin-bottom: ${({ theme }) => theme.spacing.sm};
`

const Subtitle = styled.p`
  color: ${({ theme }) => theme.colors.gray[600]};
  margin-bottom: ${({ theme }) => theme.spacing.xl};
`

const SessionsList = styled.div`
  display: flex;
  flex-direction: column;
  gap: ${({ theme }) => theme.spacing.md};
`

const SessionCard = styled.div`
  background: ${({ theme }) => theme.colors.gray[100]};
  border-radius: ${({ theme }) => theme.borderRadius.md};
  padding: ${({ theme }) => theme.spacing.lg};
`

const SessionHeader = styled.div`
  display: flex;
  align-items: center;
  gap: ${({ theme }) => theme.spacing.md};
  margin-bottom: ${({ theme }) => theme.spacing.sm};
`

const SessionDate = styled.div`
  display: flex;
  align-items: center;
  gap: ${({ theme }) => theme.spacing.xs};
  color: ${({ theme }) => theme.colors.primary};
  font-weight: ${({ theme }) => theme.fonts.weights.medium};
`

const SessionTime = styled.div`
  display: flex;
  align-items: center;
  gap: ${({ theme }) => theme.spacing.xs};
  color: ${({ theme }) => theme.colors.gray[600]};
`

const SessionNotes = styled.div`
  display: flex;
  align-items: flex-start;
  gap: ${({ theme }) => theme.spacing.xs};
  color: ${({ theme }) => theme.colors.text};
  line-height: 1.5;
`

const EmptyState = styled.div`
  text-align: center;
  padding: ${({ theme }) => theme.spacing.xl};
  color: ${({ theme }) => theme.colors.gray[600]};
`

export function ClientHistoryModal({ isOpen, onClose, clientName, sessions }: ClientHistoryModalProps) {
  if (!isOpen) return null

  return (
    <Overlay onClick={onClose}>
      <Modal onClick={e => e.stopPropagation()}>
        <CloseButton onClick={onClose}>
          <FiX />
        </CloseButton>

        <Title>Histórico de Consultas</Title>
        <Subtitle>{clientName}</Subtitle>

        <SessionsList>
          {sessions.length > 0 ? (
            sessions.map(session => (
              <SessionCard key={session.id}>
                <SessionHeader>
                  <SessionDate>
                    <FiCalendar />
                    {session.date}
                  </SessionDate>
                  <SessionTime>
                    <FiClock />
                    {session.time}
                  </SessionTime>
                </SessionHeader>
                <SessionNotes>
                  <FiFileText />
                  {session.notes}
                </SessionNotes>
              </SessionCard>
            ))
          ) : (
            <EmptyState>
              Nenhuma consulta registrada ainda.
            </EmptyState>
          )}
        </SessionsList>
      </Modal>
    </Overlay>
  )
} 