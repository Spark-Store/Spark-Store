pipeline {
  agent any
  stages {
    stage('build') {
      agent {
        docker {
          image 'jerry979/dtke:5.11.1'
        }

      }
      steps {
        sh 'mkdir build && cd build && qmake .. && make '
        archiveArtifacts(artifacts: 'build/src/spark-store', allowEmptyArchive: true, defaultExcludes: true)
      }
    }

    stage('send') {
      agent {
        dockerfile {
          filename '.gitee/Dockerfile'
        }

      }
      environment {
        gitee_token = credentials('1')
      }
      steps {
        sh "python3 .gitee/callback.py"
      }
    }

  }
}