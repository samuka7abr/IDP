import 'styled-components'

declare module 'styled-components' {
  export interface DefaultTheme {
    colors: {
      primary: string
      secondary: string
      background: string
      white: string
      text: string
      error: string
      success: string
      gray: {
        100: string
        200: string
        300: string
        400: string
        500: string
        600: string
        700: string
        800: string
        900: string
      }
    }
    fonts: {
      family: string
      sizes: {
        small: string
        medium: string
        large: string
        xlarge: string
        xxlarge: string
      }
      weights: {
        regular: number
        medium: number
        semibold: number
        bold: number
      }
    }
    spacing: {
      xs: string
      sm: string
      md: string
      lg: string
      xl: string
      xxl: string
    }
    borderRadius: {
      sm: string
      md: string
      lg: string
      full: string
    }
    shadows: {
      sm: string
      md: string
      lg: string
    }
  }
} 