import { createContext, useContext, useState, ReactNode } from 'react'

interface User {
  id: string
  name: string
  email: string
}

interface AuthContextData {
  user: User | null
  signIn: (email: string, password: string) => Promise<void>
  signOut: () => void
  isAuthenticated: boolean
}

interface AuthProviderProps {
  children: ReactNode
}

const AuthContext = createContext({} as AuthContextData)

export function AuthProvider({ children }: AuthProviderProps) {
  const [user, setUser] = useState<User | null>(null)

  const isAuthenticated = !!user

  async function signIn(email: string, password: string) {
    // Aqui você implementaria a lógica real de autenticação
    // Por enquanto, vamos simular um login bem-sucedido
    setUser({
      id: '1',
      name: 'Usuário Teste',
      email,
    })
  }

  function signOut() {
    setUser(null)
  }

  return (
    <AuthContext.Provider value={{ user, signIn, signOut, isAuthenticated }}>
      {children}
    </AuthContext.Provider>
  )
}

export const useAuth = () => useContext(AuthContext) 