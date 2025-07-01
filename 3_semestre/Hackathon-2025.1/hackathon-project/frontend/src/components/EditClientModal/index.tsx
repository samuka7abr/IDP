import { useState, useEffect } from 'react'
import styled from 'styled-components'
import { FiX } from 'react-icons/fi'

interface EditClientModalProps {
  isOpen: boolean
  onClose: () => void
  onSave: (client: { id: number; name: string; age: number; lastSession: string }) => void
  client: {
    id: number
    name: string
    age: number
    lastSession: string
  }
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
  max-width: 500px;
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
  margin-bottom: ${({ theme }) => theme.spacing.xl};
`

const Form = styled.form`
  display: flex;
  flex-direction: column;
  gap: ${({ theme }) => theme.spacing.lg};
`

const FormGroup = styled.div`
  display: flex;
  flex-direction: column;
  gap: ${({ theme }) => theme.spacing.xs};
`

const Label = styled.label`
  color: ${({ theme }) => theme.colors.text};
  font-weight: ${({ theme }) => theme.fonts.weights.medium};
`

const Input = styled.input`
  padding: ${({ theme }) => theme.spacing.md};
  border: 2px solid ${({ theme }) => theme.colors.gray[200]};
  border-radius: ${({ theme }) => theme.borderRadius.md};
  font-size: ${({ theme }) => theme.fonts.sizes.medium};
  transition: all 0.2s;

  &:focus {
    outline: none;
    border-color: ${({ theme }) => theme.colors.primary};
    box-shadow: 0 0 0 3px ${({ theme }) => theme.colors.gray[100]};
  }
`

const Button = styled.button`
  background: ${({ theme }) => theme.colors.primary};
  color: ${({ theme }) => theme.colors.white};
  padding: ${({ theme }) => theme.spacing.md};
  border-radius: ${({ theme }) => theme.borderRadius.md};
  font-size: ${({ theme }) => theme.fonts.sizes.medium};
  font-weight: ${({ theme }) => theme.fonts.weights.semibold};
  transition: all 0.2s;
  margin-top: ${({ theme }) => theme.spacing.md};

  &:hover {
    background: ${({ theme }) => theme.colors.secondary};
    transform: translateY(-1px);
  }

  &:active {
    transform: translateY(0);
  }
`

function formatDateBR(dateStr: string) {
  if (!dateStr) return '';
  const [year, month, day] = dateStr.split('-');
  return `${day.padStart(2, '0')}/${month.padStart(2, '0')}/${year}`;
}

export function EditClientModal({ isOpen, onClose, onSave, client }: EditClientModalProps) {
  const [name, setName] = useState(client.name)
  const [age, setAge] = useState(client.age.toString())
  const [lastSession, setLastSession] = useState(client.lastSession)

  useEffect(() => {
    setName(client.name)
    setAge(client.age.toString())
    setLastSession(client.lastSession)
  }, [client])

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault()
    
    if (!name || !age || !lastSession) {
      alert('Por favor, preencha todos os campos')
      return
    }

    onSave({
      id: client.id,
      name,
      age: Number(age),
      lastSession: formatDateBR(lastSession)
    })

    onClose()
  }

  if (!isOpen) return null

  return (
    <Overlay onClick={onClose}>
      <Modal onClick={e => e.stopPropagation()}>
        <CloseButton onClick={onClose}>
          <FiX />
        </CloseButton>

        <Title>Editar Paciente</Title>

        <Form onSubmit={handleSubmit}>
          <FormGroup>
            <Label>Nome Completo</Label>
            <Input
              type="text"
              value={name}
              onChange={e => setName(e.target.value)}
              placeholder="Digite o nome completo"
            />
          </FormGroup>

          <FormGroup>
            <Label>Idade</Label>
            <Input
              type="number"
              value={age}
              onChange={e => setAge(e.target.value)}
              placeholder="Digite a idade"
            />
          </FormGroup>

          <FormGroup>
            <Label>Última Sessão</Label>
            <Input
              type="date"
              value={lastSession}
              onChange={e => setLastSession(e.target.value)}
            />
          </FormGroup>

          <Button type="submit">
            Salvar Alterações
          </Button>
        </Form>
      </Modal>
    </Overlay>
  )
} 