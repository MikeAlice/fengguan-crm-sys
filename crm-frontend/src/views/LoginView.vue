<!-- 登录页面 -->
<template>
  <el-row class="login-page">
    <el-col :span="12" class="bgImg">
      <div class="container">
        <h1 id="title">01星球-CRM</h1>
        <div class="card" ref="cardElement1">
          <div class="content">
            <h2>01</h2>
            <h3>CRM系统</h3>
            <p>
              通过我们的CRM系统,您可以轻松管理组织结构,
              实现人员分配和团队管理,精确掌控资金流向, 实时监控财务状况
            </p>
            <a href="#">关注我们</a>
          </div>
        </div>
        <div class="card" ref="cardElement2">
          <div class="content">
            <h2>01</h2>
            <h3>产品亮点</h3>
            <p>
              无论您是管理人员、财务人员还是销售团队成员,
              我们的系统都为您提供了强大的工具,帮助您更高
              效地管理业务、提升团队协作和优化业务流程。
            </p>
            <a href="#">加入我们</a>
          </div>
        </div>
      </div>
    </el-col>
    <el-col :span="8" :offset="2" class="from">
      <div class="box-card">
        <p class="watter1"></p>
        <p class="watter2"></p>
        <div class="title">
          <h1>登录</h1>
        </div>
        <el-form
          label-position="top"
          :model="formData"
          status-icon
          scroll-to-error
          style="width: 50%"
        >
          <el-form-item label="账号" prop="username">
            <el-input
              class="theInput"
              prefix-icon="IconUser"
              autofocus
              v-model="formData.username"
              input-style="color: #a55eea; width: 100%;"
            ></el-input>
          </el-form-item>
          <el-form-item label="密码" prop="password">
            <el-input
              class="theInput"
              v-model="formData.password"
              prefix-icon="IconKey"
              type="password"
              show-password
              input-style="color: #a55eea;"
            ></el-input>
          </el-form-item>
          <el-form-item class="wrap" style="width: 500px">
            <el-button class="btn" type="primary" @click="submitForm()"
              >登录</el-button
            >
          </el-form-item>
        </el-form>
      </div>
    </el-col>
  </el-row>

  <!-- 验证码组件 -->
  <Verify
    mode="pop"
    :captchaType="captchaType"
    :imgSize="{ width: '400px', height: '200px' }"
    ref="verify"
    @success="handleSuccess"
  ></Verify>
</template>

<script setup>
import Verify from '@/components/verifition/Verify.vue'
import Request from '@/apis/request'
import { ref, reactive, onMounted } from 'vue'
import { login } from '@/apis/login'

import { useRouter } from 'vue-router'
import VanillaTilt from 'vanilla-tilt'
import { userStore } from '@/stores/user'
const $store = userStore()
console.log('store-in-login', $store)
// 获取router对象
const $router = useRouter()

// 定义登录数据对象
const formData = reactive({
  username: '',
  password: ''
})
// 卡片添加3d效果的dom元素
const cardElement1 = ref(null)
const cardElement2 = ref(null)
// 引用挂载3d倾斜库Vanilla-tilt.js
onMounted(() => {
  const cards = document.querySelectorAll('.card')
  cards.forEach((card) => {
    VanillaTilt.init(card, {
      max: 15,
      speed: 400,
      glare: true,
      'max-glare': 1
    })
  })
})
/**
 * 执行登录
 * @param code 验证码字符串
 */
function doLogin(code) {
  // 发送登录请求
  login(
    {
      ...formData,
      clientId: import.meta.env.VITE_CLIENT_ID,
      code: code
    },
    () => {
      // 跳转到首页
      $router.push('/dashboard')
      // 登录成功提示
      ElMessage.success('登录成功，前往首页')
    },
    () => {
      ElMessage.error('账号或密码错误')
    }
  )
}

// 定义登录提交函数
function submitForm() {
  //TODO[TEST_CODE]:测试直接进入主界面
  //$router.push('/home')

  // 弹出验证码框
  // useVerify('clickWord')
  useVerify('blockPuzzle')

  // doLogin('ccc')
}

function submitForm2() {
  //TODO[TEST_CODE]:测试直接进入主界面
  //$router.push('/home')

  // 弹出验证码框
  useVerify('clickWord')

  doLogin('dddd')
}

// 验证码组件引用
const verify = ref(null)

// 验证码类型
const captchaType = ref('')

/**
 * 弹出验证码框
 * @param type 验证码类型 blockPuzzle滑块验证 clickWord点击文字验证
 */
function useVerify(type) {
  captchaType.value = type
  verify.value.show()
}

/**
 * 验证码验证通过执行登录二次验证逻辑
 * @param res 验证通过信息
 */
function handleSuccess(res) {
  // TODO[TEST_CODE]:测试调用二次验证
  // Request.requestForm(
  //   Request.POST,
  //   '/login',
  //   { captchaVerification: res.captchaVerification },
  //   { baseURL: import.meta.env.VITE_CAPTCHA_URL }
  // )
  //   .then((res) => {
  //     console.log(res)
  //     if (res.data.repCode === '0000') {
  //       // 跳转到首页
  //       $router.push('/home')
  //       // 登录成功提示
  //       ElMessage.success('登录成功，前往首页')
  //       return
  //     }
  //     ElMessage.error('账号或密码错误')
  //   })
  //   .catch((res) => {
  //     console.log(res)
  //     ElMessage.error('账号或密码错误')
  //   })

  doLogin(res.captchaVerification)
}
</script>

<style scoped>
* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}
body {
  height: 100vh;
  overflow: hidden;
}
.btn {
  width: 16.5vw;
  left: -20px;
}
.login-page {
  height: 100vh;
  /* background-color: #5d7fba; */
  background-color: #161623;
  /* background: url('../../public/loginImg.webp') no-repeat center/cover; */
}
#title {
  font-size: 5em;
  font-family: Impact, Haettenschweiler, 'Arial Narrow Bold', sans-serif;
  letter-spacing: 4px;
  text-align: center;
  color: rgba(255, 255, 255, 0.9);
  transform: translateY(200px);
  opacity: 1;
  transition: 0.3s 0.1s;
}
/* 背景的样式 */
.bgImg {
  background-color: #a29bfe;
  border-radius: 0 40px 40px 0;
  /* background: url('../../public/loginImg.jpg') no-repeat center/cover; */
}
.bgImg {
  display: flex;
  align-items: center;
  justify-content: center;
  min-height: 100vh;
  background-color: #161623;
}
.bgImg::before {
  content: '';
  position: absolute;
  left: 0;
  top: 0;
  width: 100%;
  height: 100%;
  background: linear-gradient(#2196f3, #e91e63);
  clip-path: circle(30% at right 70%);
}
.bgImg::after {
  content: '';
  position: absolute;
  left: 0;
  top: 0;
  width: 100%;
  height: 100%;
  background: linear-gradient(#2196f3, #e91e63);
  clip-path: circle(20% at 10% 10%);
}
.container {
  position: relative;
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  min-width: 1200px;
  flex-wrap: wrap;
  z-index: 1;
}
.container .card {
  position: relative;
  top: 200px;
  width: 20%;
  height: 150px;
  /* width: 4%;
  height: 50px; */
  margin: 30px;
  box-shadow: 20px 20px 20px rgba(0, 0, 0, 0.5);
  border-radius: 20px;
  background-color: rgba(206, 217, 255, 0.2);
  overflow: hidden;
  display: flex;
  justify-content: center;
  align-items: center;
  border-top: 1px solid rgba(255, 255, 255, 0.5);
  border-left: 1px solid rgba(255, 255, 255, 0.5);
  backdrop-filter: blur(5px);
  transition: 0.5s 0.2s;
  opacity: 0;
}
.bgImg:hover .card {
  /* width: 400px; */
  top: 0;
  opacity: 1;
}
.bgImg:hover #title {
  transform: translateY(0px);
  opacity: 0;
}
.card:hover {
  height: 400px;
}
.container .card .content {
  text-align: center;
  padding: 20px;
  opacity: 0;
  transition: 0.5s;
  transform: translateY(100px);
  user-select: none;
}
.container .card:hover .content {
  transform: translateY(0px);
  opacity: 1;
}
.container .card h2 {
  position: absolute;
  font-size: 8em;
  left: 140px;
  top: -40px;
  color: rgba(255, 255, 255, 0.05);
  pointer-events: none;
}
.container .card .content h3 {
  font-size: 1.8em;
  color: #fff;
  z-index: 1;
}
.container .card .content p {
  font-size: 1em;
  color: #fff;
  font-weight: 300;
}
.container .card .content a {
  position: relative;
  display: inline-block;
  padding: 10px 20px;
  margin-top: 20px;
  color: #000;
  background: #fff;
  border-radius: 20px;
  text-decoration: none;
  font-weight: 500;
  box-shadow: 0 5px 14px rgba(0, 0, 0, 0.5);
}

.title {
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 20px 0;
  /* background-color: #ccc; */
}

.from {
  margin: 0 auto;
  /* background-color: #333; */
  color: rgb(255, 255, 255);
  z-index: 20;
}
.box-card {
  position: relative;
  width: 100%;
  height: 80%;
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  border-radius: 30% 70% 70% 30% / 45% 20% 80% 55%;
  border-top: 1px solid rgba(144, 154, 215, 0.5);
  border-left: 1px solid rgba(220, 228, 239, 0.5);
  border-right: 1px solid rgba(212, 204, 204, 0.2);
  border-bottom: 1px solid rgba(217, 205, 205, 0.2);
  background-color: rgba(22, 22, 35, 0.5);
  /* box-shadow: 6px 10px 10px 8px rgba(12, 16, 49, 0.1); */
  box-shadow: inset 10px 20px 30px rgba(45, 57, 113, 0.3),
    10px 10px 20px rgba(34, 60, 123, 0.6), 15px 15px 30px rgba(28, 85, 158, 0.2),
    inset -10px -10px 15px rgba(195, 235, 255, 0.8);
  transform: translate(0, 10%);
  backdrop-filter: blur(10px);

  animation: action 3s linear infinite alternate;
}
button {
  margin-top: 20px;
  margin-right: 10px;
}
.watter1 {
  position: absolute;
  left: 70%;
  top: 16%;
  width: 20px;
  height: 20px;
  background-color: #fffbfb;
  border-radius: 47% 53% 25% 75% / 36% 66% 34% 64%;
  animation: watter 3s linear infinite alternate;
}
.watter2 {
  position: absolute;
  left: 60%;
  top: 18%;
  width: 16px;
  height: 6px;
  background-color: #fffbfb;
  border-radius: 47% 53% 25% 75% / 36% 66% 34% 64%;
  animation: watter2 3s linear infinite alternate;
}
.wrap {
  display: flex;
  width: 100%;
  /* background-color: #fff; */
}
button {
  padding: 6px 16px;
  margin: 28px 20px;
  background-color: rgba(138, 93, 193, 0.8);
  color: #fff;
  border: 0px;
  border-radius: 4px;
}
button:hover {
  box-shadow: 0 0 4px 4px rgba(0, 0, 0, 0.4);
}
/* 动画 */
/* 动画 */
/* @keyframes action {
  25% {
    border-radius: 30% 70% 68% 32% / 47% 24% 76% 53%;
  }

  50% {
    border-radius: 36% 64% 63% 37% / 51% 34% 66% 49%;
  }

  75% {
    border-radius: 46% 54% 51% 49% / 57% 38% 62% 43%;
  }

  100% {
    border-radius: 31% 69% 64% 36% / 47% 29% 71% 53%;
  }
}
@keyframes watter {
  50% {
    left: 72%;
    top: 18%;
    border-radius: 31% 69% 64% 36% / 47% 29% 71% 53%;
    transform: scale(0.8) rotateZ(30deg);
  }
}
@keyframes watter2 {
  50% {
    opacity: 0.9;
    left: 62%;
    top: 18%;
    border-radius: 47% 56% 25% 75% / 37% 66% 30% 64%;
    transform: scale(0.8) rotateZ(30deg);
  }
} */
</style>
