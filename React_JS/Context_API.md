# How do we implement

- In context/store.js

```typescript
"use client";
import React, { createContext, useState, ReactNode } from "react";
import { io } from "socket.io-client";
type StoreContextType = {
  question: string;
  setQuestion: React.Dispatch<React.SetStateAction<string>>;
};
type StoreProviderProps = {
  children: ReactNode;
};
export const StoreContext = createContext<StoreContextType | null>(null);

export const StoreProvider: React.FC<StoreProviderProps> = ({ children }) => {
  const [question, setQuestion] = useState("Introduce yourself");
  const [answering, setAnswering] = useState(false);
  const storeContextValue: StoreContextType = {
    question,
    setQuestion,
  };
  return (
    <StoreContext.Provider value={storeContextValue}>
      {children}
    </StoreContext.Provider>
  );
};
```

- In layout.js or app.js

```typescript
import type { Metadata } from "next";
import { Inter } from "next/font/google";
import "./globals.css";
import { StoreProvider } from "./Context/store";
const inter = Inter({ subsets: ["latin"] });

export const metadata: Metadata = {
  title: "Context API",
  description: "Context",
};

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <StoreProvider>
      <html lang="en">
        <body className={inter.className}>{children}</body>
      </html>
    </StoreProvider>
  );
}
```

- Using context

```typescript
import { StoreContext } from "../Context/store";
import React, { useState, useEffect, useContext } from "react";
const storeContext = useContext(StoreContext);
```
