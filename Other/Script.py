import selenium.webdriver as webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
import time
options = Options()
options.add_argument("start-maximized")
options.add_argument("disable-infobars")
options.add_argument("--disable-extensions")


driver = webdriver.Chrome('C:/Users/Ganzorig/Downloads/Programs/chromedriver')
driver.get("https://signin.aws.amazon.com/signin?redirect_uri=https%3A%2F%2Fconsole.aws.amazon.com%2Fredshift%2F%3Fstate%3DhashArgs%2523%26isauthcode%3Dtrue&client_id=arn%3Aaws%3Aiam%3A%3A015428540659%3Auser%2Fredshift&forceMobileApp=0")
driver.find_element_by_id("resolving_input").send_keys("jane@clikdapp.com")
driver.find_element_by_id("next_button").click()
time.sleep(5)
driver.find_element_by_id("password").send_keys("$mile2Pswd")
driver.find_element_by_id("signin_button").click()

driver.find_element_by_id("gwt-debug-RedshiftLeftNavigation-clusters-link").click()
driver.find_element_by_id("rs-RedshiftGettingStarted-Launch_Quick_Flow").click()


# CREATE CLUSTER
driver.find_element_by_xpath("//*[@id='gwt-debug-Redshift-main-panel']/div[3]/div/div[4]/div/div[2]/div/div[2]/div/div/div/div[3]/div[3]/table[1]/tbody/tr/td[2]/table/tbody/tr[1]/td/div/input").clear()
driver.find_element_by_xpath("//*[@id='gwt-debug-Redshift-main-panel']/div[3]/div/div[4]/div/div[2]/div/div[2]/div/div/div/div[3]/div[3]/table[1]/tbody/tr/td[2]/table/tbody/tr[1]/td/div/input").send_keys("redshift-cluster-segment-copy")
driver.find_element_by_xpath("/html/body/div[1]/div[2]/div/div/div[2]/div/div[3]/div/div[4]/div/div[2]/div/div[2]/div/div/div/div[3]/div[3]/div[4]/table[2]/tbody/tr/td[2]/table/tbody/tr[1]/td/div/input").send_keys("aws_Pswd0")
driver.find_element_by_xpath("/html/body/div[1]/div[2]/div/div/div[2]/div/div[3]/div/div[4]/div/div[2]/div/div[2]/div/div/div/div[3]/div[3]/div[4]/table[3]/tbody/tr/td[2]/table/tbody/tr[1]/td/div/input").send_keys("aws_Pswd0")

driver.find_element_by_id("rs-QuickCreateCluster-Launch_Cluster").click()
driver.find_element_by_id("rs-QuickCreateCluster-cluster-success-launch-qe").click()
driver.find_element_by_id("rs-cmn-confirm-btn").click()
driver.find_element_by_id("gwt-debug-RedshiftLeftNavigation-clusters-link").click()


# DELETE CLUSTER
driver.find_element_by_xpath("/html/body/div[1]/div[2]/div/div/div[2]/div/div[3]/div/div[4]/div/div[2]/div/div[2]/div/div/div/div/div/div/div/div[2]/div/div/div[2]/div/div[2]/table/tbody[1]/tr/td[1]/div/label/span/span").click()
driver.find_element_by_id("rs-Redshift-cluster-menu-btn").click()
driver.find_element_by_id("rs-ClusterList-delete-btn").click()
driver.find_element_by_id("rs-Redshift-tfs-n").send_keys("cluster-new-12-2019")
driver.find_element_by_id("rs-cmn-confirm-btn").click()
