<template>
  <router-view />
</template>
<script setup>
import { useTheme } from '@/hooks/useTheme'
const { initTheme } = useTheme()
initTheme()
</script>
