/*
 * @Author: sayoriqwq 2531600563@qq.com
 * @Date: 2023-10-25 21:31:59
 * @LastEditors: sayoriqwq 2531600563@qq.com
 * @LastEditTime: 2023-11-05 22:33:06
 * @FilePath: \zero-one-crmsys\crm-frontend\src\plugins\el-icon.js
 * @Description:
 *
 * Copyright (c) 2023 by sayoriqwq 2531600563@qq.com, All Rights Reserved.
 */
// 这里导入你要使用的图标
// 写成多行避免解决冲突麻烦
import {
  Avatar,
  Bell,
  ChatDotRound,
  Check,
  CollectionTag,
  FullScreen,
  Histogram,
  Menu,
  MoonNight,
  Plus,
  Postcard,
  Refresh,
  ShoppingCart,
  Sunny,
  Van
} from '@element-plus/icons-vue'
import { Setting } from '@element-plus/icons-vue'
import { User } from '@element-plus/icons-vue'
import { Tickets } from '@element-plus/icons-vue'
import { UploadFilled } from '@element-plus/icons-vue'
import { QuestionFilled } from '@element-plus/icons-vue'
import { Delete, Edit, CaretBottom, Back } from '@element-plus/icons-vue'
import { Search } from '@element-plus/icons-vue'
import { InfoFilled } from '@element-plus/icons-vue'
import { Key } from '@element-plus/icons-vue'
import { House } from '@element-plus/icons-vue'
import { ArrowDown } from '@element-plus/icons-vue'
import { MessageBox } from '@element-plus/icons-vue'
import { Operation } from '@element-plus/icons-vue'
import { HomeFilled } from '@element-plus/icons-vue'
import { BellFilled } from '@element-plus/icons-vue'
import { CreditCard } from '@element-plus/icons-vue'
import { Comment } from '@element-plus/icons-vue'
import { View } from '@element-plus/icons-vue'
import { FolderChecked } from '@element-plus/icons-vue'
import { Upload } from '@element-plus/icons-vue'
export default (app) => {
  app.component('IconUpload', Upload)
  app.component('IconMenu', Menu)
  app.component('IconSetting', Setting)
  app.component('IconUser', User)
  app.component('IconTickets', Tickets)
  app.component('IconUpload', UploadFilled)
  app.component('IconQuestion', QuestionFilled)
  app.component('IconDelete', Delete)
  app.component('IconEdit', Edit)
  app.component('IconCaretBottom', CaretBottom)
  app.component('IconSearch', Search)
  app.component('IconInfoFilled', InfoFilled)
  app.component('IconBack', Back)
  app.component('IconKey', Key)
  app.component('IconHouse', House)
  app.component('IconRefresh', Refresh)
  app.component('IconFullScreen', FullScreen)
  app.component('IconMoonNight', MoonNight)
  app.component('IconSunny', Sunny)
  app.component('IconBell', Bell)
  app.component('IconArrowDown', ArrowDown)
  app.component('IconMessageBox', MessageBox)
  app.component('IconOperation', Operation)
  app.component('IconHomeFilled', HomeFilled)
  app.component('IconBellFilled', BellFilled)
  app.component('IconPlus', Plus)
  app.component('IconChatDotRound', ChatDotRound)
  app.component('IconCreditCard', CreditCard)
  app.component('IconComment', Comment)
  app.component('IconView', View)
  app.component('IconFolderChecked', FolderChecked)
  app.component('IconCheck', Check)
  app.component('IconHistogram', Histogram)
  app.component('IconPostCard', Postcard)
  app.component('IconAvatar', Avatar)
  app.component('IconCollectionTag', CollectionTag)
  app.component('IconShop', ShoppingCart)
  app.component('IconVan', Van)
}
